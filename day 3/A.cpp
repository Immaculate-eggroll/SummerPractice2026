#include <iostream>
#include <vector>
#include <algorithm>
 
const int MOD = 1e9 + 7;
 
int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int n, k, m;
    std::cin >> n >> k >> m;
    
    std::vector<bool> is_dangerous(n + 1, false);
    for (int i = 0; i < m; ++i) {
        int a;
        std::cin >> a;
        is_dangerous[a] = true;
    }
    
    std::vector<int> dp(n + 1, 0);
    dp[0] = 1;
    
    int window_sum = 1;
    
    for (int i = 1; i <= n; ++i) {
        if (!is_dangerous[i]) {
            dp[i] = window_sum;
        } else {
            dp[i] = 0;
        }
        
        window_sum = (window_sum + dp[i]) % MOD;
        
        if (i >= k) {
            window_sum = (window_sum - dp[i - k] + MOD) % MOD;
        }
    }
    
    std::cout << dp[n] << '\n';
}
