def is_pal(n: int) -> bool:
    s = str(n)
    for i in range(len(s)):
        j = len(s)-i-1
        if i > j: break
        if s[i] != s[j]: return False
    return True

def is_three(n: int) -> bool:
    s = str(n)
    for i in range(len(s)-2):
        if s[i:i+3].count(s[i])==3: return True
    return False

def cnt_4(n: int) -> bool:
    s = str(n)
    for i in range(len(s)):
        if s.count(s[i]) > 3: return True
    return False

def is_valid(n: int) -> bool:
    return is_pal(n) or is_three(n) or cnt_4(n)

for _ in range(int(input())):
    if is_valid(int(input())):
        print('Ronde!')
    else:
        print('Rond Nist')