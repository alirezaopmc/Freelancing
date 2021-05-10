n = int(input())
s = input()
m = int(input())
t = input()

i = 0
while i < min(n, m):
    if s[i] == t[i]:
        i += 1
    else:
        break

print(n+m-2*i)