#include <bits/stdc++.h>
using namespace std;
 
bool can(string s, int k) {
    int n = s.size();
    vector<int> diff(n + 1, 0);
    int cur = 0;
    
    for (int i = 0; i < n; i++) {
        cur ^= diff[i];
        int bit = (s[i] - '0') ^ cur;
        
        if (bit == 0) {
            if (i + k > n) return false;
            cur ^= 1;
            diff[i + k] ^= 1;
        }
    }
    
    return true;
}
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t;
    cin >> t;
    
    while (t--) {
        int n;
        string s;
        cin >> n >> s;
        
        int ans = 1;
        for (int k = n; k >= 1; k--) {
            if (can(s, k)) {
                ans = k;
                break;
            }
        }
        
        cout << ans << '\n';
    }
}
