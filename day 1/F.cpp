#include <bits/stdc++.h>
using namespace std;
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t;
    cin >> t;
    
    while (t--) {
        int n;
        cin >> n;
        
        vector<int> parent(n + 1, 0);
        for (int i = 2; i <= n; i++) {
            cin >> parent[i];
        }
        
        string s;
        cin >> s;
        
        vector<int> white(n + 1, 0), black(n + 1, 0);
        
        for (int i = 1; i <= n; i++) {
            if (s[i - 1] == 'W') white[i] = 1;
            else black[i] = 1;
        }
        
        int ans = 0;
        
        for (int v = n; v >= 1; v--) {
            if (white[v] == black[v]) ans++;
            if (v != 1) {
                white[parent[v]] += white[v];
                black[parent[v]] += black[v];
            }
        }
        
        cout << ans << '\n';
    }
}
