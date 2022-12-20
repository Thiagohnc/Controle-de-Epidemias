#include <iostream>
#include <vector>
#include "utils.hpp"
#include "epidemic_modeling.hpp"
#include "quarantine.hpp"

using namespace std;

int main(void) {
    ios_base::sync_with_stdio(false);
    
    set_rng_seed(50);
    
    EpidemicModeling no_control("../input/ws_10000_8_0.1.txt", 0.1, 0.05);
    no_control.run(200);
    
    QuarantineEpidemicModeling quarantine("../input/ws_10000_8_0.1.txt", 0.1, 0.05, 0.4, 0.15, 14);
    quarantine.run(200);
    
    QuarantineEpidemicModeling quarantine_severe("../input/ws_10000_8_0.1.txt", 0.1, 0.05, 0.4, 0.001, 30);
    quarantine_severe.run(200);
    
    return 0;
}