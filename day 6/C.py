n, m, k = map(int, input().split())
g = [[] for _ in range(n)]
for _ in range(m):
    u, v = map(int, input().split())
    u -= 1
    v -= 1
    g[u].append(v)
    g[v].append(u)
 
best_happy = -10**9
best_prod = -10**9
best_types = None
 
for mask in range(3 ** n):
    types = []
    tmp = mask
    for i in range(n):
        types.append(tmp % 3)
        tmp //= 3
    
    happy = 0
    prod = 0
    
    for i in range(n):
        if types[i] == 2:
            happy += 1
        if types[i] == 1:
            happy -= 1
            prod += 0
    
    for i in range(n):
        for j in g[i]:
            if i < j:
                ti, tj = types[i], types[j]
                
                if (ti == 0 and tj == 2) or (ti == 2 and tj == 0):
                    happy += 1
                
                if (ti == 1 and tj == 2) or (ti == 2 and tj == 1):
                    happy -= 1
                
                if (ti == 1 and tj == 0) or (ti == 0 and tj == 1):
                    prod += 1
    
    if happy >= k:
        if prod > best_prod:
            best_prod = prod
            best_happy = happy
            best_types = types[:]
 
print(best_prod)
 
res = [[], [], []]
for i in range(n):
    res[best_types[i]].append(i + 1)
 
for i in range(3):
    print(len(res[i]), *res[i])
