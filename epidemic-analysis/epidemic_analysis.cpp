#include <iostream>
#include <fstream>
#include <vector>
#include <random>
#include <climits>

#define SUSCEPTIBLE 0
#define INFECTED 1
#define REMOVED 2
#define TO_BE_INFECTED -1
#define TO_BE_REMOVED -2

using namespace std;

uniform_int_distribution<mt19937::result_type> udist(0, INT_MAX);
mt19937 rng;

int random_int(int exclusive_max_number = -1) {
	if(exclusive_max_number > -1)
		return udist(rng) % exclusive_max_number;
	return udist(rng);
}

double random_until_1() {
	return (double) random_int(1000000) / 1000000;
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
	int susceptibles, infecteds, removeds;
	
	void try_to_infect(int person) {
		if(status[person] == SUSCEPTIBLE) {
			double r = random_until_1();
			if(r <= beta) {
				status[person] = TO_BE_INFECTED;
				infecteds++;
				susceptibles--;
			}
		}
	}
	
	void try_to_remove(int person) {
		if(status[person] == INFECTED) {
			double r = random_until_1();
			if(r <= omega) {
				status[person] = TO_BE_REMOVED;
				removeds++;
				infecteds--;
			}
		}
	}
	
	void apply_status(int person) {
		if(status[person] == TO_BE_INFECTED) status[person] = INFECTED;
		if(status[person] == TO_BE_REMOVED) status[person] = REMOVED;
	}
	
public:
	EpidemicModeling(string filepath, double beta, double omega, int first_infected = -1) {
		this->graph = read_graph(filepath);
		this->beta = beta;
		this->omega = omega;
		
		first_infected = (first_infected == -1 ? random_int(graph.size()) : first_infected);
		
		this->status.resize(graph.size(), SUSCEPTIBLE);
		this->status[first_infected] = INFECTED;
		this->t = 0;
		
		this->susceptibles = graph.size() - 1;
		this->infecteds = 1;
		this->removeds = 0;
	}
	

	
	void run(int max_time) {
		print_statistics();
		
		while(t < max_time) {
			for(int u = 0; u < (int)graph.size(); u++) {
				if(status[u] == INFECTED) {
					for(int v = 0; v < (int)graph[u].size(); v++) {
						try_to_infect(graph[u][v]);
					}
					try_to_remove(u);
				}
			}

			for(int u = 0; u < (int)graph.size(); u++) apply_status(u);

			t++;
			print_statistics();
		}
	}
	
	void print_statistics() {
		cout << "t = " << t << ": " << susceptibles << " susceptibles, " << infecteds << " infecteds, " << removeds << " removeds" << endl;
	}
};

int main(void) {
	ios_base::sync_with_stdio(false);
	
	rng.seed(50);
	
	EpidemicModeling G("../input/ba_10000_3.txt", 0.1, 0.1);
	G.run(50);
	
	return 0;
}