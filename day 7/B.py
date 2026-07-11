from collections import Counter
 
t = int(input())
for _ in range(t):
    n, c, d = map(int, input().split())
    b = list(map(int, input().split()))
    
    cnt = Counter(b)
    
    a11 = min(b)
    
    matrix = []
    for i in range(n):
        row = []
        for j in range(n):
            row.append(a11 + i * c + j * d)
        matrix.append(row)
    
    matrix_flat = []
    for row in matrix:
        matrix_flat.extend(row)
    
    if Counter(matrix_flat) == cnt:
        print("YES")
    else:
        print("NO")
