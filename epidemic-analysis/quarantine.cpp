#include "control_methods.hpp"
#include "quarantine.hpp"
#include "status_constants.hpp"
#include "utils.hpp"

void QuarantineEpidemicModeling::try_to_infect_with_control_method(int person) {    
    if(status[person] == SUSCEPTIBLE) {
        double probability_to_infect = quarantine_in_progress ? beta * (1 - adherence) : beta;
        double r = random_until_1();
        if(r <= probability_to_infect) {
            status[person] = TO_BE_INFECTED;
            infecteds++;
            susceptibles--;
        }
    }
}

void QuarantineEpidemicModeling::update_quarantine_state() {
    double infected_fraction = (double) infecteds / (susceptibles + infecteds + removeds);
    
    if(infected_fraction > warning_state) {
        quarantine_in_progress = true;
        days_until_quarantine_is_over = min_quarantine_time;
    }
    else {
        if(days_until_quarantine_is_over > 0) {
            days_until_quarantine_is_over--;
        }
        if(days_until_quarantine_is_over == 0) {
            quarantine_in_progress = false;
        }
    }
}

void QuarantineEpidemicModeling::process_after_iteration() {
    update_quarantine_state();
}

QuarantineEpidemicModeling::QuarantineEpidemicModeling(std::string filepath,
                                                       double beta,
                                                       double omega,
                                                       double adherence,
                                                       double warning_state,
                                                       int min_quarantine_time,
                                                       int first_infected /*= -1*/)
: ControledEpidemicModeling(filepath, beta, omega, first_infected) {
    this->adherence = adherence;
    this->warning_state = warning_state;
    this->min_quarantine_time = min_quarantine_time;
    this->quarantine_in_progress = false;
    this->days_until_quarantine_is_over = 0;
}