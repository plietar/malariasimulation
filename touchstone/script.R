touchstone::branch_install()

touchstone::benchmark_run(
  small_population = {
    params <- malariasimulation::get_parameters(
      overrides = list(human_population=1e4))
    malariasimulation::run_simulation(10, params)
  },
  n = 4
)

touchstone::benchmark_run(
  midrange_population = {
    params <- malariasimulation::get_parameters(
      overrides = list(human_population=1e5))
    malariasimulation::run_simulation(10, params)
  },
  n = 2
)

touchstone::benchmark_run(
  large_population = {
    params <- malariasimulation::get_parameters(
      overrides = list(human_population=1e6))
    malariasimulation::run_simulation(10, params)
  },
  n = 2
)

touchstone::benchmark_analyze()
