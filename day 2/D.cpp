#include <bits/stdc++.h>
using namespace std;
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    string s;
    cin >> s;
    
    int n = s.size();
    vector<string> suf(n);
    for (int i = 0; i < n; i++) {
        suf[i] = s.substr(i);
    }
    
    sort(suf.begin(), suf.end());
    
    long long lcp_sum = 0;
    for (int i = 0; i + 1 < n; i++) {
        int l = 0;
        while (l < (int)suf[i].size() && l < (int)suf[i+1].size() && suf[i][l] == suf[i+1][l]) {
            l++;
        }
        lcp_sum += l;
    }
    
    long long total = 1LL * n * (n + 1) / 2;
    cout << total - lcp_sum << '\n';
}
