T = int(input())
for t in range(T):
    line = input()
    vals = line.split()
    r = int(vals[0]) 
    c = int(vals[1]) 
    N = int(vals[2]) 

    grid = []
    next = []
    beats = {
        "R" : "S",
        "S" : "P",
        "P" : "R"
    }

    for rws in range(r):
        row = input()
        grid.append(list(row))
        next.append(list(row))

    for n in range(N):
        for i in range(r):
            for j in range(c):
                next[i][j] = grid[i][j]

        for i in range(r):
            for j in range(c):
                curr = grid[i][j]
                if i < r - 1:
                    down = grid[i + 1][j]
                    if beats[curr] == down: next[i + 1][j] = grid[i][j]
                    if beats[down] == curr: next[i][j] = grid[i + 1][j]
                if j < c - 1:
                    right = grid[i][j + 1]
                    if beats[curr] == right: next[i][j + 1] = grid[i][j]
                    if beats[right] == curr: next[i][j] = grid[i][j + 1]
        temp = grid
        grid = next
        next = temp

    if t != 0: print()
    for i in range(r):
        print("".join(grid[i]))

