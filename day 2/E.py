s = input().strip()
n = len(s)
 
suffixes = [s[i:] for i in range(n)]
suffixes.sort()
 
lcp = [0] * (n - 1)
for i in range(n - 1):
    a = suffixes[i]
    b = suffixes[i+1]
    l = 0
    while l < len(a) and l < len(b) and a[l] == b[l]:
        l += 1
    lcp[i] = l
 
best = ""
best_val = 0
 
for length in range(1, n + 1):
    i = 0
    while i < n:
        if len(suffixes[i]) < length:
            i += 1
            continue
        
        j = i
        while j + 1 < n and lcp[j] >= length:
            j += 1
        
        cnt = j - i + 1
        t = suffixes[i][:length]
        val = length * cnt
        
        if val > best_val or (val == best_val and t < best):
            best_val = val
            best = t
        
        i = j + 1
 
print(best)
