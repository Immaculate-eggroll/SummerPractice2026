#include <bits/stdc++.h>
using namespace std;
 
vector<int> prefix_function(const string& s) {
    int n = s.size();
    vector<int> pi(n);
    for (int i = 1; i < n; i++) {
        int j = pi[i-1];
        while (j > 0 && s[i] != s[j]) j = pi[j-1];
        if (s[i] == s[j]) j++;
        pi[i] = j;
    }
    return pi;
}
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    string S;
    cin >> S;
    
    int n = S.size();
    vector<int> pi = prefix_function(S);
    
    int d = n - pi[n-1];
    if (n % d == 0) {
        cout << d << '\n';
    } else {
        cout << n << '\n';
    }
}
