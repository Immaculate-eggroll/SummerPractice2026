n = int(input())
c = [list(map(int, input().split())) for _ in range(n)]
 
INF = 10**9
dp = [[INF] * n for _ in range(1 << n)]
dp[1][0] = 0
 
for mask in range(1 << n):
    for v in range(n):
        if dp[mask][v] == INF:
            continue
        for u in range(n):
            if mask & (1 << u):
                continue
            nmask = mask | (1 << u)
            dp[nmask][u] = min(dp[nmask][u], dp[mask][v] + c[v][u])
 
ans = INF
for v in range(n):
    ans = min(ans, dp[(1 << n) - 1][v] + c[v][0])
 
print(ans)
