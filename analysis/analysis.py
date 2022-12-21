import sys
from file_reader import read_file
import matplotlib.pyplot as plt

def normalize_data(all_data):
    total_population = sum(all_data[0])
    t, susceptibles, infecteds, removeds = [], [] ,[] ,[]
    for data_from_time_t in all_data:
        t.append(data_from_time_t[0])
        susceptibles.append(data_from_time_t[1] / total_population)
        infecteds.append(data_from_time_t[2] / total_population)
        removeds.append(data_from_time_t[3] / total_population)

    return t, susceptibles, infecteds, removeds

if __name__ == '__main__':
    args = sys.argv[1:]
    filepath = args[0]
    title = ' '.join(args[1:])

    data = read_file(filepath)
    t, susceptibles, infecteds, removeds = normalize_data(data)

    plt.plot(t, susceptibles, label="suscetível", color='green')
    plt.plot(t, infecteds, label="infectado", color='red')
    plt.plot(t, removeds, label="removido", color='orange')
    plt.legend()
    plt.title(title)
    plt.show()
