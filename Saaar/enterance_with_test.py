def compute3n(n):
    if n == 0: return 1
    
    k = compute3n(n//2)
    r = 1 if n % 2 == 0 else 3
    return k * k * r

# Test
print("n = 2")
compute3n(2)
print("n = 4")
compute3n(4)
print("n = 1")
compute3n(1)