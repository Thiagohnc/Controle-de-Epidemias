import gnp
import barabasi_albert
import watts_strogatz


def generate():
    gnp.generate_graph(10000, 0.1)
    gnp.generate_graph(10000, 0.2)
    barabasi_albert.generate_graph(10000, 3)
    barabasi_albert.generate_graph(10000, 4)
    watts_strogatz.generate_graph(10000, 8, 0.1)
    watts_strogatz.generate_graph(10000, 10, 0.2)


if __name__ == '__main__':
    generate()
