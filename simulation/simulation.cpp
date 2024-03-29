#include <iostream>
#include <vector>
#include "utils.hpp"
#include "epidemic_modeling.hpp"
#include "quarantine.hpp"
#include "random_vaccination.hpp"
#include "degree_vaccination.hpp"

using namespace std;

int main(int argc, char *argv[]) {
    ios_base::sync_with_stdio(false);
    
    EpidemicModeling *E;
    
    set_rng_seed(50);
    string control_method = argv[1];
    
    if(control_method == "NoControl") {
        E = new EpidemicModeling(argv[2], atof(argv[3]), atof(argv[4]));
    }
    else if(control_method == "Quarantine") {
        E = new QuarantineEpidemicModeling(argv[2], atof(argv[3]), atof(argv[4]), atof(argv[5]), atof(argv[6]), atof(argv[7]));
    }
    else if(control_method == "RandomVaccination") {
        E = new RandomVaccinationEpidemicModeling(argv[2], atof(argv[3]), atof(argv[4]), atof(argv[5]), atof(argv[6]));
    }
    else if(control_method == "DegreeVaccination") {
        E = new DegreeVaccinationEpidemicModeling(argv[2], atof(argv[3]), atof(argv[4]), atof(argv[5]), atof(argv[6]));
    }
    else {
        cout << "Invalid Control Method: " << control_method << endl;
        return 1;
    }
    
    E->run(365 * 2);
    
    return 0;
}