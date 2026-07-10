#include <iostream>
#include <vector>
 
const int MOD = 1e9 + 7;
 
int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int l, r;
    std::cin >> l >> r;
    
    std::vector<int> dp(r + 1, 0);
    dp[1] = 1;
    
    for (int i = 1; i <= r; i++) {
        if (dp[i] == 0) continue;
        for (int j = 2 * i; j <= r; j += i) {
            dp[j] = (dp[j] + dp[i]) % MOD;
        }
    }
    
    int ans = 0;
    for (int i = l; i <= r; i++) {
        ans = (ans + dp[i]) % MOD;
    }
    
    std::cout << ans << '\n';
}
