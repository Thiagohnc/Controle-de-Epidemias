import os

def read_file(filepath):
    result = []
    with open(filepath, "r") as file:
        lines = file.read().splitlines()
        for line in lines:
            line = line.strip().split(' ')
            result.append([int(line[0]), int(line[1]), int(line[2]), int(line[3])])
    return result

def list_files_in_folder(folder):
    result = []
    files = os.listdir(folder)
    for file in files:
        result.append(os.path.join(folder, file))
    return result
