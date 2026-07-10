class TrieNode:
    __slots__ = ['child']
    def __init__(self):
        self.child = [None, None]
 
def solve():
    import sys
    input = sys.stdin.readline
    t = int(input())
    for _ in range(t):
        n = int(input())
        a = list(map(int, input().split()))
        if n == 2:
            print(a[0] ^ a[1])
            continue
 
        root = TrieNode()
 
        for val in a:
            node = root
            for bit in range(30, -1, -1):
                b = (val >> bit) & 1
                if not node.child[b]:
                    node.child[b] = TrieNode()
                node = node.child[b]
 
        ans = 0
        for val in a:
            node = root
            cur = 0
            for bit in range(30, -1, -1):
                b = (val >> bit) & 1
 
                if node.child[1 - b]:
                    cur |= (1 << bit)
                    node = node.child[1 - b]
                else:
                    node = node.child[b]
            ans = max(ans, cur)
        print(ans)
 
if __name__ == "__main__":
    solve()
