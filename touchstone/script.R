library(magrittr)

touchstone::branch_install()
fs::dir_create(dir_touchstone(), "profiles")

touchstone::benchmark_run(
  large_population = {
    branch <- gert::git_branch(repo = ".")
    fs::dir_create(dir_touchstone(), "profiles", branch)

    pprof <- jointprof:::comingle_pprof({
      set.seed(123)
      params <- malariasimulation::get_parameters(
                                                  overrides = list(human_population=1e6))
      malariasimulation::run_simulation(500, params)
    })

    file.copy(pprof, tempfile(tmpdir = file.path(dir_touchstone(), "profiles", branch)))
  },
  n = 1
)

cat(
  "Hello",
  fill = TRUE,
  file = touchstone::path_pr_comment(),
  append = TRUE)
