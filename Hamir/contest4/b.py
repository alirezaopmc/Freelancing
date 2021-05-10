left, right = map(int, input().split())

sttt = "1"

def solve(the_string):
    r = ['0'] * len(the_string)
    for i in range(len(the_string)):
        if the_string[i] == '0':
            r[i] = '1'
    return ''.join(r)

while len(sttt) < 10**5:
    sttt = sttt + solve(sttt)

print(sttt[left-1:right])