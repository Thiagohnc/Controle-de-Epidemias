#ifndef CONTROL_METHODS_H
#define CONTROL_METHODS_H

#include "epidemic_modeling.hpp"

class ControledEpidemicModeling : public EpidemicModeling {
protected:
    virtual void try_to_infect_with_control_method(int person);
    virtual void try_to_remove_with_control_method(int person);
    virtual void init_control_method();
    virtual void finish_control_method();
    virtual void process_before_iteration();
    virtual void process_after_iteration();

public:
    void run(int max_time);
    ControledEpidemicModeling(std::string filepath, double beta, double omega, int first_infected = -1);
};

#endif