#ifndef RANDOM_VACCINATION_H
#define RANDOM_VACCINATION_H

#include "vaccination.hpp"

class RandomVaccinationEpidemicModeling : public VaccinationEpidemicModeling {
public:
    RandomVaccinationEpidemicModeling(std::string filepath,
                                      double beta,
                                      double omega,
                                      double vaccination_rate,
                                      double immunization_rate,
                                      int first_infected = -1);
};

#endif