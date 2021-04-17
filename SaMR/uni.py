n = int(input("Enter n: "))
x = float(input("Enter x: "))
X = 1
p = 1
s = 0
ans = 0

i = 0
while i <= n:
    for p in range(i+1):
        X *= x
    if i % 2 == 0:
        p *= 2 * i + 1
        ans -= X / p
    else:
        s += 2
        ans += X / s
    
    i += 1

print(ans)