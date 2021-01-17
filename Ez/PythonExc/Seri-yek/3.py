def fibo(n):
    if n < 2: return n

    return fibo(n-1) + fibo(n-2)

def showAndSumFibo(n):
    s = 0
    for i in range(0, n):
        x = fibo(i)
        print('FIBO({}) = {}'.format(i, x))
        s += x
    print('SUM = ', s)

showAndSumFibo(4)