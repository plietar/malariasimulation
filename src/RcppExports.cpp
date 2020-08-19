// Generated by using Rcpp::compileAttributes() -> do not edit by hand
// Generator token: 10BE3573-1514-4C36-9D1C-5A225CD40393

#include "malariasimulation_types.h"
#include <Rcpp.h>

using namespace Rcpp;

// carrying_capacity
double carrying_capacity(const size_t timestep, const bool model_seasonality, const double days_per_timestep, const double g0, const std::vector<double>& g, const std::vector<double>& h, const double K0, const double R_bar);
RcppExport SEXP _malariasimulation_carrying_capacity(SEXP timestepSEXP, SEXP model_seasonalitySEXP, SEXP days_per_timestepSEXP, SEXP g0SEXP, SEXP gSEXP, SEXP hSEXP, SEXP K0SEXP, SEXP R_barSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< const size_t >::type timestep(timestepSEXP);
    Rcpp::traits::input_parameter< const bool >::type model_seasonality(model_seasonalitySEXP);
    Rcpp::traits::input_parameter< const double >::type days_per_timestep(days_per_timestepSEXP);
    Rcpp::traits::input_parameter< const double >::type g0(g0SEXP);
    Rcpp::traits::input_parameter< const std::vector<double>& >::type g(gSEXP);
    Rcpp::traits::input_parameter< const std::vector<double>& >::type h(hSEXP);
    Rcpp::traits::input_parameter< const double >::type K0(K0SEXP);
    Rcpp::traits::input_parameter< const double >::type R_bar(R_barSEXP);
    rcpp_result_gen = Rcpp::wrap(carrying_capacity(timestep, model_seasonality, days_per_timestep, g0, g, h, K0, R_bar));
    return rcpp_result_gen;
END_RCPP
}
// rainfall
double rainfall(const size_t t, const double days_per_timestep, const double g0, const std::vector<double>& g, const std::vector<double>& h);
RcppExport SEXP _malariasimulation_rainfall(SEXP tSEXP, SEXP days_per_timestepSEXP, SEXP g0SEXP, SEXP gSEXP, SEXP hSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< const size_t >::type t(tSEXP);
    Rcpp::traits::input_parameter< const double >::type days_per_timestep(days_per_timestepSEXP);
    Rcpp::traits::input_parameter< const double >::type g0(g0SEXP);
    Rcpp::traits::input_parameter< const std::vector<double>& >::type g(gSEXP);
    Rcpp::traits::input_parameter< const std::vector<double>& >::type h(hSEXP);
    rcpp_result_gen = Rcpp::wrap(rainfall(t, days_per_timestep, g0, g, h));
    return rcpp_result_gen;
END_RCPP
}
// create_mosquito_emergence_process_cpp
Rcpp::XPtr<process_t> create_mosquito_emergence_process_cpp(std::string mosquito, Rcpp::List odes, std::string unborn, std::string susceptible, std::string variety, double dpl);
RcppExport SEXP _malariasimulation_create_mosquito_emergence_process_cpp(SEXP mosquitoSEXP, SEXP odesSEXP, SEXP unbornSEXP, SEXP susceptibleSEXP, SEXP varietySEXP, SEXP dplSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< std::string >::type mosquito(mosquitoSEXP);
    Rcpp::traits::input_parameter< Rcpp::List >::type odes(odesSEXP);
    Rcpp::traits::input_parameter< std::string >::type unborn(unbornSEXP);
    Rcpp::traits::input_parameter< std::string >::type susceptible(susceptibleSEXP);
    Rcpp::traits::input_parameter< std::string >::type variety(varietySEXP);
    Rcpp::traits::input_parameter< double >::type dpl(dplSEXP);
    rcpp_result_gen = Rcpp::wrap(create_mosquito_emergence_process_cpp(mosquito, odes, unborn, susceptible, variety, dpl));
    return rcpp_result_gen;
END_RCPP
}
// create_mosquito_infection_process_cpp
Rcpp::XPtr<process_t> create_mosquito_infection_process_cpp(const std::string mosquito, const std::string human, const std::vector<std::string>& states, const std::vector<std::string>& variables);
RcppExport SEXP _malariasimulation_create_mosquito_infection_process_cpp(SEXP mosquitoSEXP, SEXP humanSEXP, SEXP statesSEXP, SEXP variablesSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< const std::string >::type mosquito(mosquitoSEXP);
    Rcpp::traits::input_parameter< const std::string >::type human(humanSEXP);
    Rcpp::traits::input_parameter< const std::vector<std::string>& >::type states(statesSEXP);
    Rcpp::traits::input_parameter< const std::vector<std::string>& >::type variables(variablesSEXP);
    rcpp_result_gen = Rcpp::wrap(create_mosquito_infection_process_cpp(mosquito, human, states, variables));
    return rcpp_result_gen;
END_RCPP
}
// create_mosquito_model
Rcpp::XPtr<MosquitoModel> create_mosquito_model(std::vector<double> init, double beta, double de, double mue, double K0, double gamma, double dl, double mul, double dp, double mup, size_t total_M, bool model_seasonality, double days_per_timestep, double g0, std::vector<double> g, std::vector<double> h, double R_bar);
RcppExport SEXP _malariasimulation_create_mosquito_model(SEXP initSEXP, SEXP betaSEXP, SEXP deSEXP, SEXP mueSEXP, SEXP K0SEXP, SEXP gammaSEXP, SEXP dlSEXP, SEXP mulSEXP, SEXP dpSEXP, SEXP mupSEXP, SEXP total_MSEXP, SEXP model_seasonalitySEXP, SEXP days_per_timestepSEXP, SEXP g0SEXP, SEXP gSEXP, SEXP hSEXP, SEXP R_barSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< std::vector<double> >::type init(initSEXP);
    Rcpp::traits::input_parameter< double >::type beta(betaSEXP);
    Rcpp::traits::input_parameter< double >::type de(deSEXP);
    Rcpp::traits::input_parameter< double >::type mue(mueSEXP);
    Rcpp::traits::input_parameter< double >::type K0(K0SEXP);
    Rcpp::traits::input_parameter< double >::type gamma(gammaSEXP);
    Rcpp::traits::input_parameter< double >::type dl(dlSEXP);
    Rcpp::traits::input_parameter< double >::type mul(mulSEXP);
    Rcpp::traits::input_parameter< double >::type dp(dpSEXP);
    Rcpp::traits::input_parameter< double >::type mup(mupSEXP);
    Rcpp::traits::input_parameter< size_t >::type total_M(total_MSEXP);
    Rcpp::traits::input_parameter< bool >::type model_seasonality(model_seasonalitySEXP);
    Rcpp::traits::input_parameter< double >::type days_per_timestep(days_per_timestepSEXP);
    Rcpp::traits::input_parameter< double >::type g0(g0SEXP);
    Rcpp::traits::input_parameter< std::vector<double> >::type g(gSEXP);
    Rcpp::traits::input_parameter< std::vector<double> >::type h(hSEXP);
    Rcpp::traits::input_parameter< double >::type R_bar(R_barSEXP);
    rcpp_result_gen = Rcpp::wrap(create_mosquito_model(init, beta, de, mue, K0, gamma, dl, mul, dp, mup, total_M, model_seasonality, days_per_timestep, g0, g, h, R_bar));
    return rcpp_result_gen;
END_RCPP
}
// mosquito_model_get_states
std::vector<double> mosquito_model_get_states(Rcpp::XPtr<MosquitoModel> model);
RcppExport SEXP _malariasimulation_mosquito_model_get_states(SEXP modelSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< Rcpp::XPtr<MosquitoModel> >::type model(modelSEXP);
    rcpp_result_gen = Rcpp::wrap(mosquito_model_get_states(model));
    return rcpp_result_gen;
END_RCPP
}
// create_ode_stepping_process_cpp
Rcpp::XPtr<process_t> create_ode_stepping_process_cpp(Rcpp::List odes, const std::string mosquito, const std::vector<std::string> states, const std::string variety);
RcppExport SEXP _malariasimulation_create_ode_stepping_process_cpp(SEXP odesSEXP, SEXP mosquitoSEXP, SEXP statesSEXP, SEXP varietySEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< Rcpp::List >::type odes(odesSEXP);
    Rcpp::traits::input_parameter< const std::string >::type mosquito(mosquitoSEXP);
    Rcpp::traits::input_parameter< const std::vector<std::string> >::type states(statesSEXP);
    Rcpp::traits::input_parameter< const std::string >::type variety(varietySEXP);
    rcpp_result_gen = Rcpp::wrap(create_ode_stepping_process_cpp(odes, mosquito, states, variety));
    return rcpp_result_gen;
END_RCPP
}
// mosquito_model_step
void mosquito_model_step(Rcpp::XPtr<MosquitoModel> model, size_t total_M);
RcppExport SEXP _malariasimulation_mosquito_model_step(SEXP modelSEXP, SEXP total_MSEXP) {
BEGIN_RCPP
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< Rcpp::XPtr<MosquitoModel> >::type model(modelSEXP);
    Rcpp::traits::input_parameter< size_t >::type total_M(total_MSEXP);
    mosquito_model_step(model, total_M);
    return R_NilValue;
END_RCPP
}

RcppExport SEXP run_testthat_tests();

static const R_CallMethodDef CallEntries[] = {
    {"_malariasimulation_carrying_capacity", (DL_FUNC) &_malariasimulation_carrying_capacity, 8},
    {"_malariasimulation_rainfall", (DL_FUNC) &_malariasimulation_rainfall, 5},
    {"_malariasimulation_create_mosquito_emergence_process_cpp", (DL_FUNC) &_malariasimulation_create_mosquito_emergence_process_cpp, 6},
    {"_malariasimulation_create_mosquito_infection_process_cpp", (DL_FUNC) &_malariasimulation_create_mosquito_infection_process_cpp, 4},
    {"_malariasimulation_create_mosquito_model", (DL_FUNC) &_malariasimulation_create_mosquito_model, 17},
    {"_malariasimulation_mosquito_model_get_states", (DL_FUNC) &_malariasimulation_mosquito_model_get_states, 1},
    {"_malariasimulation_create_ode_stepping_process_cpp", (DL_FUNC) &_malariasimulation_create_ode_stepping_process_cpp, 4},
    {"_malariasimulation_mosquito_model_step", (DL_FUNC) &_malariasimulation_mosquito_model_step, 2},
    {"run_testthat_tests", (DL_FUNC) &run_testthat_tests, 0},
    {NULL, NULL, 0}
};

RcppExport void R_init_malariasimulation(DllInfo *dll) {
    R_registerRoutines(dll, NULL, CallEntries, NULL, NULL);
    R_useDynamicSymbols(dll, FALSE);
}
