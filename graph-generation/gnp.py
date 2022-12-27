import networkx as nx
import os
import global_config
from graph_seeds import graph_seeds


def generate_graph(n, p, ngraphs):
    for graph_num in range(ngraphs):
        generated_and_connected = False
        while not generated_and_connected:
            graph = nx.fast_gnp_random_graph(n, p, seed=graph_seeds[graph_num])
            generated_and_connected = nx.is_connected(graph)

        filepath = os.path.join(global_config.input_folder, f'gnp_{n}_{p}_{graph_num}.txt')
        nx.write_edgelist(graph, filepath, data=False)
