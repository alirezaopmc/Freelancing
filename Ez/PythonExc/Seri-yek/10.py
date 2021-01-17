def gcd(n, m):
    if m == 0: return n

    return gcd(m, n % m)

def lcm(n, m):
    return n * m // gcd(n, m)


n, m = map(int, input().split())

print('GCD = ', gcd(n, m))
print('LCM = ', lcm(n, m))