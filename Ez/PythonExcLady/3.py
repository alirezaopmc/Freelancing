def matrixMult(A, B):
    n, m, k, l = len(A), len(A[0]), len(B), len(B[0])

    C = [[0 for j in range(l)] for i in range(n)]
    for i in range(n):
        for j in range(l):
            for t in range(k):
                C[i][j] += A[i][t] * B[t][j]
    return C


def multMatrixFromFile():
    a = open('a.txt', 'r')
    b = open('b.txt', 'r')

    A = list(map(lambda s: s.split(','), a.read().split('\n')))
    for i in range(len(A)):
        for j in range(len(A[0])):
            A[i][j] = int(A[i][j])

    B = list(map(lambda s: s.split(','), b.read().split('\n')))
    for i in range(len(B)):
        for j in range(len(B[0])):
            B[i][j] = int(B[i][j])
    
    n, m, k, l = len(A), len(A[0]), len(B), len(B[0])

    c = open('c.txt', 'w')
    if m != k:
        c.write('Error')
    else:
        C = matrixMult(A, B)
        s = ""
        
        for i in range(n):
            for j in range(l):
                s += str(C[i][j])
                if j != l-1:
                    s += ' '
            s += '\n'

        c.write(s)
    c.close()

multMatrixFromFile()
            