
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

template<class A>
class IterableBitsetPrivate {
    public:
    size_t max_n;
    size_t n;
    size_t num_bits;
    std::vector<A> bitmap;
};

template<typename A>
size_t count_range(const IterableBitset<A>& bitset, size_t start, size_t end) {
    const IterableBitsetPrivate<A>* p =
        reinterpret_cast<const IterableBitsetPrivate<A>*>(&bitset);
    constexpr size_t num_bits = sizeof(A) * 8;

    if (start == end) {
        return 0;
    } else if (start / num_bits == end / num_bits) {
        A mask =
            (static_cast<A>(1) << (end % num_bits)) -
            (static_cast<A>(1) << (start % num_bits));
        return popcount(p->bitmap[start / num_bits] & mask);
    } else {
        A mask = -(static_cast<A>(1) << (start % num_bits));
        size_t n = popcount(p->bitmap[start / num_bits] & mask);

        start = (start + num_bits) / num_bits * num_bits;
        for (; start + num_bits <= end; start += num_bits) {
            n += popcount(p->bitmap[start / num_bits]);
        }
        start = (end / num_bits) * num_bits;
                                
        if (start < end) {
            mask = (static_cast<A>(1) << (end % num_bits)) - 1;
            n += popcount(p->bitmap[end / num_bits] & mask);
        }

        return n;
    }
}

//[[Rcpp::export]]
std::vector<size_t> bitset_index2_cpp(
    Rcpp::XPtr<individual_index_t> a,
    Rcpp::XPtr<individual_index_t> b
) {
    size_t n = 1;
    size_t cursor = 0;

    auto values = std::vector<size_t>();
    for (const auto& v : *b) {
        if (a->find(v) != a->end()) {
            n += count_range(*a, cursor, v);
            cursor = v;
            values.push_back(n);
        } else {
            // values.push_back(NA);
        }
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
