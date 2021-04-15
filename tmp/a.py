def ispal(s):
    n = len(s)
    for i in range(n//2):
        if s[i] != s[n-i-1]:
            return False
    return True

for _ in range(int(input())):
    s = list(input())
    n = len(s)
    if s.count('a') == n:
        print('NO')
    else:
        print('YES')
        if not ispal('a' + ''.join(s)):
            print('a' + ''.join(s))
        else:
            print(''.join(s) + 'a')