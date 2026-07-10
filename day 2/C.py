s = input().strip()
n = len(s)
 
MOD = 10**9 + 7
P = 257
 
p = [1] * (n + 1)
for i in range(1, n + 1):
    p[i] = (p[i-1] * P) % MOD
 
h = [0] * (n + 1)
for i in range(n):
    h[i+1] = (h[i] * P + ord(s[i])) % MOD
 
hr = [0] * (n + 1)
for i in range(n):
    hr[i+1] = (hr[i] * P + ord(s[n-1-i])) % MOD
 
def get_hash(arr, l, r):
    return (arr[r] - arr[l] * p[r-l]) % MOD
 
ans = 1
for L in range(2, n + 1):
    hash1 = get_hash(h, 0, L)
    hash2 = get_hash(hr, n - L, n)
    
    if hash1 == hash2:
        ans = L
 
print(ans)
