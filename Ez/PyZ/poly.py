def showPolynomial(coefficients: list):
    coefficients.reverse()
    n = len(coefficients)
    for i in range(n):
        if coefficients[i] == 0: continue
        sign = '+' if coefficients[i] >= 0 else '-'
        if coefficients[i] >= 0 and i == 0: sign = ''
        if i < n-1: print('{}{}x^{} '.format(sign, abs(coefficients[i]), n-i-1), end='')
        else: print('{}{}'.format(sign, abs(coefficients[i])), end='')
    print()


showPolynomial([1, 0, 3, -3, 5])