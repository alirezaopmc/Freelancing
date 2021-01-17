n, k = map(int, input().split())

L = list(map(int, input().split()))

def preprocess(L, n, k):
    P = [0] * k

    for x in L:
        P[x] += 1

    for i in range(1, k):
        P[i] += P[i-1]
    
    return P

P = preprocess(L, n, k)

def query(P, a, b):
    if a == 0:
        return P[b]
    else:
        return P[b] - P[a]  

a, b = map(int, input().split())

print(query(P, a, b))

