n, k = map(int, input().split())
a = list(map(int, input().split()))
 
ans = 0
 
def dfs(pos, cnt, cur):
    global ans
    if cnt == k:
        ans = max(ans, cur)
        return
    if pos == n:
        return
    if cnt + (n - pos) < k:
        return
    dfs(pos + 1, cnt + 1, cur ^ a[pos])
    dfs(pos + 1, cnt, cur)
 
dfs(0, 0, 0)
print(ans)
