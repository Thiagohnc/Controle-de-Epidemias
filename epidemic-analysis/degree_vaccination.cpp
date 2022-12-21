#include "control_methods.hpp"
#include "degree_vaccination.hpp"
#include "vaccination.hpp"
#include "status_constants.hpp"
#include "utils.hpp"
#include <algorithm>
#include <vector>
#include <iostream>

DegreeVaccinationEpidemicModeling::DegreeVaccinationEpidemicModeling(std::string filepath,
                                                                     double beta,
                                                                     double omega,
                                                                     double vaccination_rate,
                                                                     double immunization_rate,
                                                                     int first_infected /*= -1*/)
: VaccinationEpidemicModeling(filepath, beta, omega, vaccination_rate, immunization_rate, first_infected) {
    std::vector<std::pair<int,int>>vaccination_order(graph.size());
    
    for(int i = 0; i < (int)vaccination_order.size(); i++) {
        vaccination_order[i] = std::make_pair(-graph[i].size(), i);
    }
    
    sort(vaccination_order.begin(), vaccination_order.end());
    
    for(int i = 0; i < (int)vaccination_order.size(); i++) {
        vaccination_queue.push(vaccination_order[i].second);
    }
    
    vaccination_order.clear();
}