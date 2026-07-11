n = int(input())
a = []
for i in range(n):
    a.append(list(map(int, input().split())))
 
dp = a[-1][:]
 
for i in range(n - 2, -1, -1):
    ndp = []
    for j in range(i + 1):
        ndp.append(a[i][j] + max(dp[j], dp[j + 1]))
    dp = ndp
 
print(dp[0])
