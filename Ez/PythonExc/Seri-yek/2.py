def isPrime(n):
    if n == 1: return False

    for i in range(2, n):
        if n % i == 0: return False
        if i * i > n: break
    
    return True