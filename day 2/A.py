import sys
 
def solve():
    S = sys.stdin.readline().strip()
    T = sys.stdin.readline().strip()
    
    n = len(S)
    
    if S == T:
        print(0)
        return
    
    double_S = S + S
    
    min_shift = n
    start = 0
    
    while True:
        pos = double_S.find(T, start)
        if pos == -1 or pos >= n:
            break
        shift = (n - pos) % n
        if shift < min_shift:
            min_shift = shift
            if min_shift == 0:
                break
        start = pos + 1
    
    print(min_shift if min_shift < n else -1)
 
if __name__ == "__main__":
    solve()
