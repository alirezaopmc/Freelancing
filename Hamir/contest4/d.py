n, m = map(int, input().split())
a, b = 0, 0
s = [input() for i in range(n)]
t = [input() for i in range(n)]
for x in s:
    a += x.count('*')
for x in t:
    b += x.count('*')
print(a, b)