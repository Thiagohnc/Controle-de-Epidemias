#include "control_methods.hpp"
#include "status_constants.hpp"
#include "utils.hpp"

void ControledEpidemicModeling::run(int max_time) {
    print_statistics();
    init_control_method();
    
    while(t < max_time) {
        process_before_iteration();
        
        for(int u = 0; u < (int)graph.size(); u++) {
            if(status[u] == INFECTED) {
                for(int v = 0; v < (int)graph[u].size(); v++) {
                    try_to_infect_with_control_method(graph[u][v]);
                }
                try_to_remove_with_control_method(u);
            }
        }

        for(int u = 0; u < (int)graph.size(); u++) apply_status(u);

        process_after_iteration();

        t++;
        print_statistics();
    }
    
    finish_control_method();
}

ControledEpidemicModeling::ControledEpidemicModeling(std::string filepath, double beta, double omega, int first_infected /*= -1*/)
: EpidemicModeling(filepath, beta, omega, first_infected) {}

// When this method is not overridden, it calls the EpidemicModeling try_to_infect method
void ControledEpidemicModeling::try_to_infect_with_control_method(int person) {
    try_to_infect(person);
}

// When this method is not overridden, it calls the EpidemicModeling try_to_remove method
void ControledEpidemicModeling::try_to_remove_with_control_method(int person) {
    try_to_remove(person);
}

void ControledEpidemicModeling::init_control_method() {}
void ControledEpidemicModeling::finish_control_method() {}
void ControledEpidemicModeling::process_before_iteration() {}
void ControledEpidemicModeling::process_after_iteration() {}