myList = ['fateme', 12, ['cat', 'dog'], 'fateme']


def removeFromMyList(element):
    global myList

    i = 0
    n = len(myList)
    while i < n:
        if myList[i] == element:
            myList.pop(i)
            n -= 1
        i += 1
    
print(myList)
removeFromMyList('fateme')
print(myList)