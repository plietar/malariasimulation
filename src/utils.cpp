
#include <Rcpp.h>
#include "Random.h"
#include <individual.h>

//[[Rcpp::export]]
void random_seed(size_t seed) {
    Random::get_instance().seed(seed);
}

//[[Rcpp::export]]
std::string random_save_state() {
    return Random::get_instance().save_state();
}

//[[Rcpp::export]]
void random_restore_state(std::string state) {
    return Random::get_instance().restore_state(state);
}

//[[Rcpp::export]]
std::vector<size_t> bernoulli_multi_p_cpp(const std::vector<double> p) {
    auto values = Random::get_instance().bernoulli_multi_p(p);
    for (auto i = 0u; i < values.size(); ++i) {
        values[i]++;
    }
    return values;
}

//[[Rcpp::export]]
std::vector<size_t> bitset_index_cpp(
    Rcpp::XPtr<individual_index_t> a,
    Rcpp::XPtr<individual_index_t> b
    ) {
    auto values = std::vector<size_t>();
    auto i = 1u;
    for (const auto& v : *a) {
        if (b->find(v) != b->cend()) {
            values.push_back(i);
        }
        ++i;
    }
    return values;
}

//[[Rcpp::export]]
Rcpp::XPtr<individual_index_t> bitset_at_logical_cpp(
    Rcpp::XPtr<individual_index_t> source,
    Rcpp::LogicalVector filter
    ) {
    if (source->size() != filter.size()) {
        Rcpp::stop("vector of logicals must equal the size of the bitset");
    }

    individual_index_t result(source->max_size());

    auto source_it = source->begin();
    auto filter_it = filter.begin();
    for (; source_it != source->end() && filter_it != filter.end(); ++source_it, ++filter_it) {
        if (*filter_it) {
            result.insert(*source_it);
        }
    }

    return Rcpp::XPtr<individual_index_t>(new individual_index_t(std::move(result)), true);
}

//[[Rcpp::export(rng = false)]]
Rcpp::IntegerVector fast_weighted_sample(
    size_t size,
    std::vector<double> probs
    ) {
    Rcpp::IntegerVector values(size);
    Random::get_instance().prop_sample_bucket(
        size,
        probs,
        INTEGER(values)
    );
    values = values + 1;
    return values;
}

//[[Rcpp::export]]
std::vector<Rcpp::XPtr<individual_index_t>> bitset_partition_cpp(
    Rcpp::XPtr<individual_index_t> source,
    Rcpp::NumericVector values,
    Rcpp::NumericMatrix weigths)
{
    size_t nrows = weigths.rows();
    size_t ncols = weigths.cols();

    if (source->size() != nrows) {
        Rcpp::stop("number of rows must be equal to the size of the bitset");
    }
    if (source->size() != values.size()) {
        Rcpp::stop("number of rows must be equal to the size of the bitset");
    }

    std::vector<Rcpp::XPtr<individual_index_t>> result;
    for (size_t i = 0; i < ncols; i++) {
        result.emplace_back(new individual_index_t(source->max_size()), true);
    }

    // Incrementing bitset iterators is actually a little slow. We don't need
    // the value on every iteration, only when there is a match. Skipping
    // forward with `source_it += source_n` when needed is faster than
    // `source_it++` on every iteration.
    auto source_it = source->begin();
    size_t source_n = 0;

    auto value_it = values.begin();
    for (size_t row = 0; row < nrows; ++row, ++value_it, ++source_n) {
        double v = *value_it;
        for (size_t col = 0; col < ncols; ++col) {
            double w = weigths(row, col);
            if (v < w) {
                source_it += source_n;
                source_n = 0;
                result[col]->insert(*source_it);
                break;
            } else {
                v -= w;
            }
        }
    }

    return result;
}
