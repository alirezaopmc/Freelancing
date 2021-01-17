from math import sqrt

def distance(x1, y1, x2, y2):
    return sqrt( (x1 - x2) ** 2 + (y1 - y2) ** 2 )

x1, y1, x2, y2 = map(int, input().split())

print(distance(x1, y1, x2, y2))