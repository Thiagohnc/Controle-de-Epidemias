#ifndef QUARANTINE_H
#define QUARANTINE_H

#include "control_methods.hpp"

class QuarantineEpidemicModeling : public ControledEpidemicModeling {
protected:
    double adherence; // Fraction of contact that will be avoided during quarantine
    double warning_state; // Fraction of infected people to start quarantine
    int min_quarantine_time; 
    bool quarantine_in_progress;
    int days_until_quarantine_is_over;

    virtual void try_to_infect_with_control_method(int person) override;
    void update_quarantine_state();
    virtual void process_after_iteration() override;

public:
    QuarantineEpidemicModeling(std::string filepath,
                               double beta,
                               double omega,
                               double adherence,
                               double warning_state,
                               int min_quarantine_time,
                               int first_infected = -1);
};

#endif