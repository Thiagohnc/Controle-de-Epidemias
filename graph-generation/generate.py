import gnp
import barabasi_albert


def generate():
    gnp.generate_graph(10000, 0.1)
    gnp.generate_graph(10000, 0.2)
    gnp.generate_graph(10000, 0.3)
    gnp.generate_graph(10000, 0.4)
    barabasi_albert.generate_graph(10000, 3)
    barabasi_albert.generate_graph(10000, 4)
    barabasi_albert.generate_graph(20000, 3)
    barabasi_albert.generate_graph(20000, 4)


if __name__ == '__main__':
    generate()
