def read_file(filepath):
    result = []
    with open(filepath, "r") as file:
        lines = file.read().splitlines()
        for line in lines:
            line = line.strip().split(' ')
            result.append([int(line[0]), int(line[1]), int(line[2]), int(line[3])])
    return result
