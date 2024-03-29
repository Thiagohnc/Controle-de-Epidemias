#include <vector>
#include <iostream>
#include "utils.hpp"
#include "status_constants.hpp"
#include "epidemic_modeling.hpp"

using namespace std;

EpidemicModeling::EpidemicModeling(string filepath, double beta, double omega, int first_infected) {
    this->graph = read_graph(filepath);
    this->beta = beta;
    this->omega = omega;
    
    this->status.resize(graph.size(), SUSCEPTIBLE);
    
    // Infects 5 random persons
    for(int i = 0; i < 5; i++) {
        int infected = random_int(graph.size());
        this->status[infected] = INFECTED;
    }
    
    this->t = 0;
    
    this->susceptibles = graph.size() - 1;
    this->infecteds = 1;
    this->removeds = 0;
}

EpidemicModeling::EpidemicModeling() {}

void EpidemicModeling::try_to_infect(int person) {
    if(status[person] == SUSCEPTIBLE) {
        double r = random_until_1();
        if(r <= beta) {
            status[person] = TO_BE_INFECTED;
            infecteds++;
            susceptibles--;
        }
    }
}

void EpidemicModeling::try_to_remove(int person) {
    if(status[person] == INFECTED) {
        double r = random_until_1();
        if(r <= omega) {
            status[person] = TO_BE_REMOVED;
            removeds++;
            infecteds--;
        }
    }
}

void EpidemicModeling::apply_status(int person) {
    if(status[person] == TO_BE_INFECTED) status[person] = INFECTED;
    if(status[person] == TO_BE_REMOVED) status[person] = REMOVED;
}

void EpidemicModeling::run(int max_time) {
    print_statistics();
    
    while(t < max_time) {
        for(int u = 0; u < (int)graph.size(); u++) {
            if(status[u] == INFECTED) {
                for(int v = 0; v < (int)graph[u].size(); v++) {
                    try_to_infect(graph[u][v]);
                }
                try_to_remove(u);
            }
        }

        for(int u = 0; u < (int)graph.size(); u++) apply_status(u);

        t++;
        print_statistics();
    }
}

void EpidemicModeling::print_statistics() {
    cout << t << " " << susceptibles << " " << infecteds << " " << removeds << endl;
}