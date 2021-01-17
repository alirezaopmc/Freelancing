from math import sin, cos, sqrt, radians

def translate(x, y, theta):
    x2 = x * cos(theta) - y * sin(theta)
    y2 = x * sin(theta) + y * cos(theta)

    return (x2, y2)

def distance(x1, y1, x2, y2):
    return sqrt( (x1 - x2) ** 2 + (y1 - y2) ** 2 )

print("Enter the coordinates of the planet: (x, y)")
x, y = map(int, input().split())
print("Enter the coordinates of the satellite: (px, py)")
px, py = map(int, input().split())

theta = radians(10)

d1 = distance(px, py, x, y)
(x2, y2) = translate(x, y, theta)
d2 = distance(px, py, x2, y2)

print('Before = {} and After = {}'.format(d1, d2))