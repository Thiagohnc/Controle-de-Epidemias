#ifndef VACCINATION_H
#define VACCINATION_H

#include "control_methods.hpp"
#include <vector>
#include <queue>

class VaccinationEpidemicModeling : public ControledEpidemicModeling {
protected:
    double vaccination_rate; // Fraction of total population that will be vaccinated daily
	double immunization_rate; // Fraction of vaccinated people that will be immunized
    std::vector<bool> immunized;
    std::queue<int> vaccination_queue;

    void try_to_infect_with_control_method(int person) override;
    void vaccinate();
    void process_before_iteration() override;

public:
    VaccinationEpidemicModeling(std::string filepath,
                                double beta,
                                double omega,
                                double vaccination_rate,
                                double immunization_rate,
                                int first_infected = -1);
};

#endif