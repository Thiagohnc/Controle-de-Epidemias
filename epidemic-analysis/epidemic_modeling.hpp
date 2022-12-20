#ifndef EPIDEMIC_MODELING_H
#define EPIDEMIC_MODELING_H

#include <vector>
#include <string>

class EpidemicModeling {
protected:
    std::vector<std::vector<int>> graph;
    std::vector<int> status;
    double beta;
    double omega;
    double t;
    int susceptibles, infecteds, removeds;
    
    void try_to_infect(int person);
    void try_to_remove(int person);
    void apply_status(int person);
    
public:
    EpidemicModeling(std::string filepath, double beta, double omega, int first_infected = -1);

    void run(int max_time);
    void print_statistics();
};

#endif