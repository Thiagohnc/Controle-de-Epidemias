#include <iostream>
#include <fstream>
#include <vector>
#include <random>
#include <climits>

#define SUSCEPTIBLE 0
#define INFECTED 1
#define REMOVED 2

using namespace std;

uniform_int_distribution<mt19937::result_type> udist(0, INT_MAX);
mt19937 rng;

int random_number(int exclusive_max_number = -1) {
	if(exclusive_max_number > -1)
		return udist(rng) % exclusive_max_number;
	return udist(rng);
}

vector<vector<int>> read_graph(string filepath) {
	vector<vector<int>> graph;
	vector<pair<int,int> > edges;
	int a, b, max_idx = -1;
	ifstream file;
	
	file.open(filepath);
	while(file >> a) {
		file >> b;
		max_idx = max(max(a, b), max_idx);
		edges.push_back(make_pair(a,b));
	}
	file.close();
	
	graph.resize(max_idx + 1);
	for(auto edge: edges) {
		graph[edge.first].push_back(edge.second);
		graph[edge.second].push_back(edge.first);
	}
	edges.clear();

	return graph;
}

class EpidemicModeling {
private:
	vector<vector<int>> graph;
	vector<int> status;
	double beta;
	double omega;
	double t;
public:
	EpidemicModeling(string filepath, double beta, double omega, int first_infected = -1) {
		this->graph = read_graph(filepath);
		this->beta = beta;
		this->omega = omega;
		
		first_infected = (first_infected == -1 ? random_number(graph.size()) : first_infected);
		
		this->status.resize(graph.size(), SUSCEPTIBLE);
		this->status[first_infected] = INFECTED;
		this->t = 0;
	}
};

int main(void) {
	ios_base::sync_with_stdio(false);
	
	rng.seed(50);
	
	EpidemicModeling G("../input/ba_10000_3.txt", 0.2, 0.1);
	
	return 0;
}