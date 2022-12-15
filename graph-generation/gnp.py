import networkx as nx
import os
import global_config


def generate_graph(n, p):
    graph = nx.fast_gnp_random_graph(n, p, seed=global_config.seed)

    filepath = os.path.join(global_config.input_folder, f'gnp_{n}_{p}.txt')
    nx.write_edgelist(graph, filepath, data=False)
