import sys
from file_reader import list_files_in_folder, read_file
import matplotlib.pyplot as plt
import numpy as np

def normalize_data(all_data):
    total_population = sum(all_data[0])
    t, susceptibles, infecteds, removeds = [], [] ,[] ,[]
    for data_from_time_t in all_data:
        t.append(data_from_time_t[0])
        susceptibles.append(data_from_time_t[1] / total_population)
        infecteds.append(data_from_time_t[2] / total_population)
        removeds.append(data_from_time_t[3] / total_population)

    return np.array(t), np.array(susceptibles), np.array(infecteds), np.array(removeds)


def get_statistics(folder):
    input_files = list_files_in_folder(folder)
    list_t, list_susceptibles, list_infecteds, list_removeds = [], [], [], []
    for input_file in input_files:
        data = read_file(input_file)
        t, susceptibles, infecteds, removeds = normalize_data(data)
        list_t.append(t)
        list_susceptibles.append(susceptibles)
        list_infecteds.append(infecteds)
        list_removeds.append(removeds)

    mean_t = sum(list_t)/len(input_files)
    mean_susceptibles = sum(list_susceptibles)/len(input_files)
    mean_infecteds = sum(list_infecteds)/len(input_files)
    mean_removeds = sum(list_removeds)/len(input_files)

    return mean_t, mean_susceptibles, mean_infecteds, mean_removeds


def set_time_upperbound(_t, _susceptibles, _infecteds, _removeds, tmax=200):
    while tmax < len(_removeds) and _removeds[tmax] > _removeds[tmax-20] + 0.01:
        tmax += 1

    return _t[:tmax], _susceptibles[:tmax], _infecteds[:tmax], _removeds[:tmax]


if __name__ == '__main__':
    args = sys.argv[1:]

    plot_path = f'..\\plots\\{args[0]}'
    suptitle = ' '.join(args[1].split('_'))
    folders = []
    titles = []

    rows = len(args[2:])//2

    model_tags = ['gnp', 'ba', 'ws']
    model_names = ['ER', 'BA', 'WS']
    for i in range(rows):
        folders.append([])
        titles.append([])
        for j in range(3):
            folders[i].append(f'..\\output\\{model_tags[j]}\\{args[2*i+2]}')
            titles[i].append(model_names[j] + ' - ' + ' '.join(args[2*i+3].split('_')))

    fig, axs = plt.subplots(len(args[2:])//2, 3)
    for i in range(rows):
        for j in range(3):
            t, susceptibles, infecteds, removeds = get_statistics(folders[i][j])
            t, susceptibles, infecteds, removeds = set_time_upperbound(t, susceptibles, infecteds, removeds)
            ax = axs[i, j] if len(args[1:])//2 > 1 else axs[j]
            ax.plot(t, susceptibles, '--', label="suscetível", color='green')
            ax.plot(t, infecteds, '-', label="infectado", color='red')
            ax.plot(t, removeds, ':', label="removido", color='orange')
            ax.set_xlabel('Tempo')
            ax.set_ylabel('Fração de indivíduos')
            ax.set_title(titles[i][j])

    fig.suptitle(suptitle)
    fig.set_figheight(rows * 3)
    fig.set_figwidth(9)
    fig.tight_layout()
    plt.savefig(plot_path)
