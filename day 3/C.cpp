#include <iostream>
#include <vector>
 
const int MOD = 1e9 + 7;
 
int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int n, m, k;
    std::cin >> n >> m >> k;
    
    std::vector<std::vector<bool>> dangerous(n + 1, std::vector<bool>(m + 1, false));
    
    for (int i = 0; i < k; i++) {
        int x, y;
        std::cin >> x >> y;
        dangerous[x][y] = true;
    }
    
    std::vector<std::vector<int>> dp(n + 1, std::vector<int>(m + 1, 0));
    
    dp[0][0] = 1;
    
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= m; j++) {
            if (i == 0 && j == 0) continue;
            
            if (dangerous[i][j]) {
                dp[i][j] = 0;
                continue;
            }
            
            long long ways = 0;
            if (i > 0) ways += dp[i-1][j];
            if (j > 0) ways += dp[i][j-1];
            
            dp[i][j] = ways % MOD;
        }
    }
    
    std::cout << dp[n][m] << '\n';
}
