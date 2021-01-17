import random

INF = 10**20

a = open('input.txt', 'r').read().split('\n')

n = int(a[0])
# print(a)

index = 2
ladders = []
while a[index] != 'S':
    ladders.append( list(map(int, a[index].split())) )
    index += 1

index += 1
snakes = []
while a[index] != '-1':
    snakes.append( list(map(int, a[index].split())) )
    index += 1

teleport = [i for i in range(n)]
for l in ladders:
    teleport[l[0]-1] = l[1]-1
for s in snakes:
    teleport[s[0]-1] = s[1]-1



adj = [-1] * n

for i in range(n):
    if i != teleport[i]:
        adj[i] = [teleport[i]]
    else:
        adj[i] = [j for j in range(i+1, min(100, i+7))]

# for i in range(n):
#     print(i, adj[i])


chk = [False] * n
par = [-1] * n
q = [0]

def bfs(i):
    global adj
    global teleport
    global chk
    global par

    while len(q) > 0:
        t = q.pop(0)

        for v in adj[t]:
            if not chk[v]:
                chk[v] = True
                q.append(v)
                par[v] = t

bfs(0)
# print(par)

target = n-1

way = []
while target != 0:
    way.append(target)
    target = par[target]

way.append(0)
way.reverse()
# print(way)

cnt = -1
for x in way:
    if x == teleport[x]:
        cnt += 1

output = open('output.txt', 'w')
output.write(str(cnt) + '\n')


i = 0
while i < len(way)-1 and cnt:
    x = way[i]
    if x == teleport[x]:
        output.write(str(way[i+1]-x) + '\n')
        cnt -= 1
    
    i += 1

output.close()