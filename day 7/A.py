t = int(input())
for _ in range(t):
    n, a, b = map(int, input().split())
    
    pairs = n // 2
    rem = n % 2
    
    cost1 = pairs * min(2 * a, b) + rem * a
    
    print(cost1)
