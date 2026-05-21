import sys

dr = [-1, 0, 1, 0]
dc = [0, 1, 0, -1]
r, c = 0, 0

grid = []
for x in range(8):
    line = input()
    grid.append(list(line))
    for y in range(8):
        if line[y] == "T":
            r = x
            c = y

dir = 1
line = input()
bug = False;

for move in line:
    ##print(r, " ", c, " ", dir)
    if bug:
        break

    match move:
        case "F": 
            r += dr[dir]
            c += dc[dir]

            if r < 0 or r >= 8 or c < 0 or c >= 8:
                bug = True;
            elif grid[r][c] == "C" or grid[r][c] == "I":
                bug = True;
        case "R":
            dir = (dir + 1) % 4
        case "L":
            dir = (dir + 3) % 4
        case "X":
            tr = r + dr[dir]
            tc = c + dc[dir]
            if tr < 0 or tr >= 8 or tc < 0 or tc >= 8:
                bug = True
            elif grid[tr][tc] == "I":
                grid[tr][tc] = "."
                ##print(grid[tr][tc])
            elif grid[tr][tc] != "D":
                bug = True
if bug:
    print("Bug!")
elif grid[r][c] == "D":
    print("Diamond!")
else:
    print("Bug!")

