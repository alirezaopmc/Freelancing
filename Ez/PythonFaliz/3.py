from random import randint

myRandomList = [randint(0, 101) for i in range(10)]

def printDescendingArray(arr):
    myRandomList.sort()
    n = len(arr)

    for i in range(n-1, -1, -1):
        print(arr[i], end=' ')

print(myRandomList)
printDescendingArray(myRandomList)