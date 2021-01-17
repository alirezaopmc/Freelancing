def squareRoot(n):
    if n == 1: return 1

    for i in range(n):
        if i * i > n: return i-1