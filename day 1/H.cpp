#include <bits/stdc++.h>
using namespace std;
 
const int MOD = 676767677;
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
 
    int t;
    cin >> t;
 
    while (t--) {
        int n, m;
        cin >> n >> m;
 
        vector<int> b(n);
        for (int i = 0; i < n; i++) {
            cin >> b[i];
        }
 
        bool ok = true;
 
        for (int i = 0; i < n; i++) {
            if (b[i] == 0) continue;
            bool has_neighbor = false;
            if (i > 0 && b[i - 1] < b[i]) has_neighbor = true;
            if (i + 1 < n && b[i + 1] < b[i]) has_neighbor = true;
            if (!has_neighbor) {
                ok = false;
                break;
            }
        }
 
        if (!ok) {
            cout << 0 << '\n';
            continue;
        }
 
        vector<int> cnt(m + 1, 0);
        for (int i = 0; i < n; i++) {
            cnt[b[i] + 1]++;
        }
        for (int i = 1; i <= m; i++) {
            cnt[i] += cnt[i - 1];
        }
 
        long long ans = 1;
 
        for (int i = 0; i < n; i++) {
            if (b[i] == 0) continue;
            int t = b[i];
 
            bool has_earlier = false;
            if (i > 0 && b[i - 1] < t - 1) has_earlier = true;
            if (i + 1 < n && b[i + 1] < t - 1) has_earlier = true;
 
            long long ways;
            if (has_earlier) {
                ways = cnt[t] - cnt[t - 1];
            } else {
                ways = cnt[t];
            }
 
            ans = (ans * ways) % MOD;
        }
 
        cout << ans << '\n';
    }
}
