def printFromAtoB(a, b):
    if a < b:
        for i in range(a, b+1):
            print(i, end=' ')
    else:
        for i in range(a, b-1, -1):
            print(i, end=' ')

a, b = map(int, input().split())
printFromAtoB(a, b)