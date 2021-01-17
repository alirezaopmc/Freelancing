myList = ['fateme', 12, ['cat', 'dog'], 'fateme']


def getIndices(element):
    global myList

    result = []
    i = 0
    n = len(myList)
    while i < n:
        if myList[i] == element:
            result.append(i)
        i += 1
    return result
    
print(myList)
print(getIndices('fateme'))