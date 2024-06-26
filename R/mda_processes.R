#' @title Create listeners for MDA events
#' @param variables the variables available in the model
#' @param drug the drug to administer
#' @param timesteps timesteps for each round
#' @param coverages the coverage for each round
#' @param min_ages minimum age for the target population for each round
#' @param max_ages maximum age for the target population for each round
#' @param correlations correlation parameters
#' @param int_name the name of this intervention (either 'smc' or 'mda')
#' @param parameters the model parameters
#' @param renderer the model renderer object
#' @description will create a listener for administering each round of drugs
#' @noRd
create_mda_listeners <- function(
  variables,
  drug,
  timesteps,
  coverages,
  min_ages,
  max_ages,
  correlations,
  int_name,
  parameters,
  renderer
  ) {
  renderer$set_default(paste0('n_', int_name, '_treated'), 0)
  function(timestep) {
    time_index = which(timesteps == timestep)
    coverage <- coverages[[time_index]]
    age <- get_age(variables$birth$get_values(), timestep)

    in_age <- which((age > min_ages[[time_index]]) & (age < max_ages[[time_index]]))
    target <- in_age[sample_intervention(in_age, int_name, coverage, correlations)]

    renderer$render(paste0('n_', int_name, '_treated'), length(target), timestep)
    
    successful_treatments <- bernoulli(
      length(target),
      parameters$drug_efficacy[[drug]]
    )
    to_move <- individual::Bitset$new(parameters$human_population)
    to_move$insert(target[successful_treatments])

    if (to_move$size() > 0) {
      # Move detectable
      clinical <- variables$state$get_index_of('D')
      asymptomatic <- variables$state$get_index_of('A')
      detectable <- calculate_asymptomatic_detectable(
        variables$state,
        variables$birth,
        variables$id,
        parameters,
        timestep
      )
      to_treat <- clinical$or(asymptomatic$and(detectable))
      variables$state$queue_update(
        'Tr',
        to_treat$copy()$and(to_move)
      )

      # Move everyone else
      other <- to_move$copy()$and(to_treat$not(TRUE))
      if (other$size() > 0) {
        variables$state$queue_update('S', other)
      }

      # Update infectivity
      variables$infectivity$queue_update(
        variables$infectivity$get_values(
          to_move
        ) * parameters$drug_rel_c[[drug]],
        to_move
      )

      # Update drug
      variables$drug$queue_update(drug, to_move)
      variables$drug_time$queue_update(timestep, to_move)
    }
  }
}

#' @title Calculate asymptomatic detectable individuals
#'
#' @description Sample a bitset of individuals who are asymptomatic and also
#' detectable by microscopy
#' @param state human infection state
#' @param birth variable for birth of the individual
#' @param immunity to detection
#' @param parameters model parameters
#' @param timestep current timestep
#'
#' @noRd
calculate_asymptomatic_detectable <- function(
    state,
    birth,
    immunity,
    parameters,
    timestep
  ) {
  asymptomatic <- state$get_index_of('A')
  prob <- probability_of_detection(
    get_age(birth$get_values(asymptomatic), timestep),
    immunity$get_values(asymptomatic),
    parameters
  )
  bitset_at(asymptomatic, bernoulli_multi_p(prob))
}
