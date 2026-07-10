#include <bits/stdc++.h>
using namespace std;
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
 
    int t;
    cin >> t;
 
    while (t--) {
        int x, y;
        cin >> x >> y;
 
        int n = x + y;
        bool ok = true;
 
        if (n == 1) {
            if (!(x == 0 && y == 1)) ok = false;
        } else if (n % 2 == 0) {
            if (x < 1 || x > n / 2) ok = false;
        } else {
            if (x < 0 || x > (n - 1) / 2) ok = false;
        }
 
        if (!ok) {
            cout << "NO\n";
            continue;
        }
 
        cout << "YES\n";
 
        if (n == 1) {
            continue;
        }
 
        vector<pair<int, int>> edges;
 
        if (n % 2 == 0) {
            int L = 2 * x - 1;
            int m = n - 1 - L;
 
            for (int i = 1; i <= L; i++) {
                edges.push_back({i, i + 1});
            }
 
            for (int i = L + 2; i <= n; i++) {
                edges.push_back({1, i});
            }
        } else {
            int L = 2 * x;
            int m = n - 1 - L;
 
            for (int i = 1; i <= L; i++) {
                edges.push_back({i, i + 1});
            }
 
            for (int i = L + 2; i <= n; i++) {
                edges.push_back({1, i});
            }
        }
 
        for (auto &e : edges) {
            cout << e.first << " " << e.second << "\n";
        }
    }
 
    return 0;
}
