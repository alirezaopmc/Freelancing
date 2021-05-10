n, m = map(int, input().split())

a = list(map(int, input().split()))

b = sorted(a)
t = b[m-1]

i = 0
while a[i] != t: i += 1

a[i] = a[0]
sm = []
lg = []

for x in a[1:]:
    sm.append(x) if t > x else lg.append(x)

print(*sm, t, *lg)