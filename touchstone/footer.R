documentation <- "https://lorenzwalthert.github.io/touchstone/articles/inference.html"
workflow <- Sys.getenv("WORKFLOW_URL")

glue::glue(
  "\n\nFurther explanation regarding interpretation and",
  " methodology can be found in the [documentation]({documentation}).",
  "\nPlots and raw data are available as artifacts of",
  " [the workflow run]({workflow})."
)
