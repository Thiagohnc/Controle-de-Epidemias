#include <iostream>
#include <vector>
#include "utils.hpp"
#include "epidemic_modeling.hpp"

using namespace std;

int main(void) {
	ios_base::sync_with_stdio(false);
	
	set_rng_seed(50);
	
	EpidemicModeling G("../input/ba_10000_3.txt", 0.1, 0.1);
	G.run(50);
	
	return 0;
}