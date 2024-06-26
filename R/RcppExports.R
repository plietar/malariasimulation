# Generated by using Rcpp::compileAttributes() -> do not edit by hand
# Generator token: 10BE3573-1514-4C36-9D1C-5A225CD40393

create_adult_mosquito_model <- function(growth_model, mu, tau, susceptible, foim) {
    .Call(`_malariasimulation_create_adult_mosquito_model`, growth_model, mu, tau, susceptible, foim)
}

adult_mosquito_model_update <- function(model, mu, foim, susceptible, f) {
    invisible(.Call(`_malariasimulation_adult_mosquito_model_update`, model, mu, foim, susceptible, f))
}

adult_mosquito_model_save_state <- function(model) {
    .Call(`_malariasimulation_adult_mosquito_model_save_state`, model)
}

adult_mosquito_model_restore_state <- function(model, state) {
    invisible(.Call(`_malariasimulation_adult_mosquito_model_restore_state`, model, state))
}

create_adult_solver <- function(model, init, r_tol, a_tol, max_steps) {
    .Call(`_malariasimulation_create_adult_solver`, model, init, r_tol, a_tol, max_steps)
}

create_aquatic_mosquito_model <- function(beta, de, mue, k_timeseries, gamma, dl, mul, dp, mup, total_M, model_seasonality, g0, g, h, R_bar, mum, f, rainfall_floor) {
    .Call(`_malariasimulation_create_aquatic_mosquito_model`, beta, de, mue, k_timeseries, gamma, dl, mul, dp, mup, total_M, model_seasonality, g0, g, h, R_bar, mum, f, rainfall_floor)
}

aquatic_mosquito_model_update <- function(model, total_M, f, mum) {
    invisible(.Call(`_malariasimulation_aquatic_mosquito_model_update`, model, total_M, f, mum))
}

create_aquatic_solver <- function(model, init, r_tol, a_tol, max_steps) {
    .Call(`_malariasimulation_create_aquatic_solver`, model, init, r_tol, a_tol, max_steps)
}

carrying_capacity <- function(timestep, model_seasonality, g0, g, h, K0, R_bar, rainfall_floor) {
    .Call(`_malariasimulation_carrying_capacity`, timestep, model_seasonality, g0, g, h, K0, R_bar, rainfall_floor)
}

eggs_laid <- function(beta, mu, f) {
    .Call(`_malariasimulation_eggs_laid`, beta, mu, f)
}

rainfall <- function(t, g0, g, h, floor) {
    .Call(`_malariasimulation_rainfall`, t, g0, g, h, floor)
}

exponential_process_cpp <- function(variable, rate) {
    .Call(`_malariasimulation_exponential_process_cpp`, variable, rate)
}

solver_get_states <- function(solver) {
    .Call(`_malariasimulation_solver_get_states`, solver)
}

solver_set_states <- function(solver, t, state) {
    invisible(.Call(`_malariasimulation_solver_set_states`, solver, t, state))
}

solver_step <- function(solver) {
    invisible(.Call(`_malariasimulation_solver_step`, solver))
}

create_timeseries <- function(size, default_value) {
    .Call(`_malariasimulation_create_timeseries`, size, default_value)
}

timeseries_at <- function(timeseries, timestep, linear) {
    .Call(`_malariasimulation_timeseries_at`, timeseries, timestep, linear)
}

timeseries_push <- function(timeseries, value, timestep) {
    invisible(.Call(`_malariasimulation_timeseries_push`, timeseries, value, timestep))
}

timeseries_save_state <- function(timeseries) {
    .Call(`_malariasimulation_timeseries_save_state`, timeseries)
}

timeseries_restore_state <- function(timeseries, state) {
    invisible(.Call(`_malariasimulation_timeseries_restore_state`, timeseries, state))
}

random_seed <- function(seed) {
    invisible(.Call(`_malariasimulation_random_seed`, seed))
}

random_save_state <- function() {
    .Call(`_malariasimulation_random_save_state`)
}

random_restore_state <- function(state) {
    invisible(.Call(`_malariasimulation_random_restore_state`, state))
}

bernoulli_multi_p_cpp <- function(p) {
    .Call(`_malariasimulation_bernoulli_multi_p_cpp`, p)
}

bitset_index_cpp <- function(a, b) {
    .Call(`_malariasimulation_bitset_index_cpp`, a, b)
}

fast_weighted_sample <- function(size, probs) {
    .Call(`_malariasimulation_fast_weighted_sample`, size, probs)
}

