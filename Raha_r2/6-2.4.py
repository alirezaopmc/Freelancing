import random 

k = random.randint(3, 5)

n = 2 ** k - 1

def giveAnArray(n):
    a = [i for i in range(n + 1)]

    random.shuffle(a)

    a.pop()

    return a


a = giveAnArray(n)
print(a)


def findMissing(a, n):
    for i in range(n):
        if a[i] != n:
            x = a[i]
            y = a[x]
            a[x] = x
            a[i] = y

    for i in range(n):
        if a[i] == n: return i
    
    return n

print(findMissing(a, n))
print(a)