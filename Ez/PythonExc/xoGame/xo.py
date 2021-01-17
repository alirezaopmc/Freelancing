import os

grid = [[ 0 for j in range(3) ] for i in range(3) ]

turn = 0

"""
x => 1 (zoj ha)
y => -1 (fard ha)
"""

def show_grid(msg = None):
    os.system('cls')
    for i in range(3):
        for j in range(3):
            c = grid[i][j]
            if c == -1:
                print('O', end='')
            elif c == 0:
                print(' ', end='')
            else:
                print('X', end='')

            if j == 2:
                print()
            else:
                print('|', end='')
    
    if msg:
        print(msg)

def translate(x):
    x -= 1
    i = x // 3
    j = x % 3

    return (i, j)

def is_empty(x):
    (i, j) = translate(x)
    return grid[i][j] == 0

def put(x):
    (i, j) = translate(x)
    grid[i][j] = -1 if turn % 2 else 1

def sameTwo(i, j, _i, _j):
    if grid[i][j] == 0: return False
    return grid[i][j] == grid[_i][_j]

def sameThree(i, j, _i, _j, __i, __j):
    if grid[i][j] == 0: return False
    return sameTwo(i, j, _i, _j) and sameTwo(i, j, __i, __j)

def gameover():
    for i in range(3):
        if sameThree(i, 0, i, 1, i, 2): return True
    for j in range(3):
        if sameThree(0, j, 1, j, 2, j): return True
    
    return sameThree(0, 0, 1, 1, 2, 2) or sameThree(0, 2, 1, 1, 2, 0)

def run():
    x = int(input())

    if not 1 <= x <= 9:
        show_grid('Wrong Number, Try again!')
    elif not is_empty(x):
        show_grid('Full Cell, Try Again!')
    else:
        put(x)
        show_grid()

def main():
    global turn

    show_grid()
    while not gameover():
        run()
        turn += 1
    if turn % 2:
        print('X Won')
    else:
        print('O Won')
        


main()