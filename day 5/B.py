n, k = map(int, input().split())
mod = 10**9 + 7
 
dp = [0] * (n + 1)
pref = [0] * (n + 1)
 
dp[0] = 1
pref[0] = 1
 
for i in range(1, n + 1):
    left = max(0, i - k)
    dp[i] = (pref[i - 1] - (pref[left - 1] if left > 0 else 0)) % mod
    pref[i] = (pref[i - 1] + dp[i]) % mod
 
print(dp[n])
