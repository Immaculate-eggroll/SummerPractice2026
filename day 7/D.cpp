#include <bits/stdc++.h>
using namespace std;
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t;
    cin >> t;
    
    while (t--) {
        int n, m, k;
        cin >> n >> m >> k;
        
        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        
        vector<int> b(m);
        for (int i = 0; i < m; i++) {
            cin >> b[i];
        }
        
        unordered_map<int, int> need;
        for (int x : b) {
            need[x]++;
        }
        
        unordered_map<int, int> cur;
        int matches = 0;
        int ans = 0;
        
        for (int i = 0; i < n; i++) {
            cur[a[i]]++;
            if (need.count(a[i]) && cur[a[i]] <= need[a[i]]) {
                matches++;
            }
            
            if (i >= m) {
                int left = a[i - m];
                cur[left]--;
                if (need.count(left) && cur[left] < need[left]) {
                    matches--;
                }
            }
            
            if (i >= m - 1) {
                if (matches >= k) {
                    ans++;
                }
            }
        }
        
        cout << ans << '\n';
    }
}
