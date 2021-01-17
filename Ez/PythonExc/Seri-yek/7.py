def printMults(n, limit):
    k = n
    while k < limit:
        print(k)
        k += n


printMults(int(input()), 100)