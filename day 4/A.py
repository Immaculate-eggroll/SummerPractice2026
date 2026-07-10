t = int(input())
for _ in range(t):
    a, b, c = map(int, input().split())
    
    max_prod = 0
    for i in range(6):
        for j in range(6 - i):
            x = a + i
            y = b + j
            z = c + (5 - i - j)
            max_prod = max(max_prod, x * y * z)
    
    print(max_prod)
