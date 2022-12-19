#include <random>
#include <climits>
#include <vector>
#include <fstream>

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

void set_rng_seed(int seed) {
	rng.seed(seed);
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