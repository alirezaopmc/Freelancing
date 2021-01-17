def dictOfString(s):
    d = {}
    for c in lower(s):
        if c != ' ':
            if c in d:
                d[c] += 1
            else:
                d[c] = 1
    return d

print(dictOfString(input()))