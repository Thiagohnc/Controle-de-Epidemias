import random

graph_seeds = []


def init(seed_generator_seed, ngraphs):
    random.seed(seed_generator_seed)

    for _ in range(ngraphs):
        new_graph_seed_generated = False
        while not new_graph_seed_generated:
            new_graph_seed = random.randint(1, 10000000)
            new_graph_seed_generated = new_graph_seed not in graph_seeds
        graph_seeds.append(new_graph_seed)
