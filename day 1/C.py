t = int(input())
for _ in range(t):
    n = int(input())
    
    mins = list(range(1, n+1))
    medians = [n + 1 + 2*i for i in range(n)]
    
    all_nums = set(range(1, 3*n+1))
    used = set(mins) | set(medians)
    maxs = sorted(list(all_nums - used))
    ans = []
    for i in range(n):
        ans.extend([mins[i], medians[i], maxs[i]])
    print(' '.join(map(str, ans)))
