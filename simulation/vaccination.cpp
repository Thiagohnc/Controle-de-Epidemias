#include "control_methods.hpp"
#include "vaccination.hpp"
#include "status_constants.hpp"
#include "utils.hpp"

void VaccinationEpidemicModeling::try_to_infect_with_control_method(int person) {
    if(status[person] == SUSCEPTIBLE && immunized[person] == false) {
        double r = random_until_1();
        if(r <= beta) {
            status[person] = TO_BE_INFECTED;
            infecteds++;
            susceptibles--;
        }
    }
}

void VaccinationEpidemicModeling::vaccinate() {
    int population = susceptibles + infecteds + removeds;
    int vaccines = population * vaccination_rate;
    
    while(!vaccination_queue.empty() && vaccines > 0) {
        double r = random_until_1();
        
        int person_to_vaccinate = vaccination_queue.front();
        if(r <= immunization_rate) {
            immunized[person_to_vaccinate] = true;
        }
        
        vaccination_queue.pop();
        vaccines--;
    }
}

void VaccinationEpidemicModeling::process_before_iteration() {
    vaccinate();
}

VaccinationEpidemicModeling::VaccinationEpidemicModeling(std::string filepath,
                                                         double beta,
                                                         double omega,
                                                         double vaccination_rate,
                                                         double immunization_rate,
                                                         int first_infected /*= -1*/)
: ControledEpidemicModeling(filepath, beta, omega, first_infected) {
    this->vaccination_rate = vaccination_rate;
    this->immunization_rate = immunization_rate;
    this->immunized.resize(graph.size(), false);
}