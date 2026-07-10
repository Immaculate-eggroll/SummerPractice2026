#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
 
int main() {
    int t;
    cin >> t;
    while (t--) {
        vector<int> a(7);
        int sum = 0;
        int mx = -100;
        for (int i = 0; i < 7; i++) {
            cin >> a[i];
            sum += a[i];
            mx = max(mx, a[i]);
        }
        cout << -sum + 2 * mx << '\n';
    }
}
