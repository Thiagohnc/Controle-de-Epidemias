#ifndef DEGREE_VACCINATION_H
#define DEGREE_VACCINATION_H

#include "vaccination.hpp"

class DegreeVaccinationEpidemicModeling : public VaccinationEpidemicModeling {
public:
    DegreeVaccinationEpidemicModeling(std::string filepath,
                                      double beta,
                                      double omega,
                                      double vaccination_rate,
                                      double immunization_rate,
                                      int first_infected = -1);
};

#endif