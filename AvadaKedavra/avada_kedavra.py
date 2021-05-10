n, k = map(int, input().split())
a = list(map(int, input().split()))
mx = max(a)

def solve(arr, partial, k, left, right):
    if left == right:
        partial[left] = arr[left] if left == 0 else partial[left - 1] + arr[left]
        return int(arr[left] % k == 0) + int(partial[left] % k == 0)

    m = left + (right - left) // 2

    ans = solve(arr, partial, k, left, m) + solve(arr, partial, k, m+1, right)

    for l in range(left, m+1):
        for r in range(m+1, left+1):
            ans += int((partial[r] - partial[l]) % k == 0)

    return ans

for i in range(n):
    if a[i] == mx:
        a = a[:i] + a[i+1:]
        break

p = [0] * n

print(solve(a, p, k, 0, n-2))






