t = int(input())
for _ in range(t):
    n, m = map(int, input().split())
    c = []
    for i in range(n):
        c.append(list(map(int, input().split())))
    
    dp = [0] * (m + 1)
    
    for i in range(n):
        ndp = [0] * (m + 1)
        for j in range(m + 1):
            for k in range(m - j + 1):
                val = 0 if k == 0 else c[i][k - 1]
                ndp[j + k] = max(ndp[j + k], dp[j] + val)
        dp = ndp
    
    print(dp[m])
