import global_config
import gnp
import barabasi_albert
import watts_strogatz
import graph_seeds


def generate(ngraphs):
    gnp.generate_graph(n=100000, p=0.0005, ngraphs=ngraphs)
    barabasi_albert.generate_graph(n=100000, m=50, ngraphs=ngraphs)
    watts_strogatz.generate_graph(n=100000, k=50, p=0.1, ngraphs=ngraphs)


if __name__ == '__main__':
    graph_seeds.init(global_config.seed, global_config.ngraphs)
    generate(global_config.ngraphs)
