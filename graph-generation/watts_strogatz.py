import networkx as nx
import os
import global_config


def generate_graph(n, k, p):
    graph = nx.watts_strogatz_graph(n, k, p, seed=global_config.seed)

    filepath = os.path.join(global_config.input_folder, f'ws_{n}_{k}_{p}.txt')
    nx.write_edgelist(graph, filepath, data=False)
