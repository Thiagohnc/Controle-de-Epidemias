import networkx as nx
import os
import global_config


def generate_graph(n, m):
    graph = nx.barabasi_albert_graph(n, m, seed=global_config.seed)

    filepath = os.path.join(global_config.input_folder, f'ba_{n}_{m}.txt')
    nx.write_edgelist(graph, filepath, data=False)
