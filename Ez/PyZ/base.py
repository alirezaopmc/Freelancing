# r bayad kamtar az 10 bashe
def convertToBaseR(number, r = 8):
    result = ''

    while number:
        k = number % r
        result = str(k) + result
        number //= r
    
    return result


ans = convertToBaseR(12)
print(ans)

