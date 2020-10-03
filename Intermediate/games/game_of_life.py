# Don't Panic.

import os, sys

def peers(x, y):
    neighbours = 0
    if 0 <= x + 1 <= rows - 1 and 0 <= y <= columns - 1 and board[x + 1][y] == "X":
        neighbours += 1
    if 0 <= x - 1 <= rows - 1 and 0 <= y <= columns - 1 and board[x - 1][y] == "X":
        neighbours += 1
    if 0 <= x <= rows - 1 and 0 <= y + 1 <= columns - 1 and board[x][y + 1] == "X":
        neighbours += 1
    if 0 <= x <= rows - 1 and 0 <= y - 1 <= columns - 1 and board[x][y - 1] == "X":
        neighbours += 1
    if 0 <= x + 1 <= rows - 1 and 0 <= y + 1 <= columns - 1 and board[x + 1][y + 1] == "X":
        neighbours += 1
    if 0 <= x + 1 <= rows - 1 and 0 <= y - 1 <= columns - 1 and board[x + 1][y - 1] == "X":
        neighbours += 1
    if 0 <= x - 1 <= rows - 1 and 0 <= y + 1 <= columns - 1 and board[x - 1][y + 1] == "X":
        neighbours += 1
    if 0 <= x - 1 <= rows - 1 and 0 <= y - 1 <= columns - 1 and board[x - 1][y - 1] == "X":
        neighbours += 1
    return neighbours

rows = int(input("Rows: "))
columns = int(input("Columns: "))
board = [["."] * columns for _ in range(rows)]
iterations = int(input("Iterations: "))
print("Enter each live cell at the beginning with the row and column number separated by a space (top right is 0, 0). Enter \"-1 -1\" to move on:")
while True:
    x, y = map(int, input().split())
    if x + y == -2:
        break
    board[x][y] = "X"

for i in range(iterations):
    os.system('cls' if os.name == 'nt' else 'clear') # clears console on all platforms
    new = [["."] * columns for _ in range(rows)]
    for r in range(rows):
        for c in range(columns):
            neighbours = peers(r, c)
            if board[r][c] == ".": # dead cell
                if neighbours == 3:
                    new[r][c] = "X"
            else: # live cell
                if neighbours == 2 or neighbours == 3:
                    new[r][c] = "X"
    board = new
    sys.stdout.write(f"Iteration {i}\n")
    sys.stdout.write("\n".join("".join(line) for line in board) + "\n")
