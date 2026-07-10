#include <bits/stdc++.h>
using namespace std;
 
const int MAXP = 200000;
vector<int> primes;
 
void sieve() {
    vector<bool> is_prime(MAXP + 1, true);
    is_prime[0] = is_prime[1] = false;
    for (int i = 2; i <= MAXP; i++) {
        if (is_prime[i]) {
            primes.push_back(i);
            if (1LL * i * i <= MAXP) {
                for (long long j = 1LL * i * i; j <= MAXP; j += i)
                    is_prime[j] = false;
            }
        }
    }
}
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    sieve();
    
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<long long> a(n);
        a[0] = 1;
        if (n == 2) {
            a[1] = primes[0];
        } else {
            a[1] = 1LL * primes[0] * primes[1];
            for (int i = 2; i < n - 1; i++) {
                a[i] = 1LL * primes[i - 1] * primes[i];
            }
            a[n - 1] = primes[n - 2];
        }
        for (int i = 0; i < n; i++) {
            cout << a[i] << (i + 1 == n ? '\n' : ' ');
        }
    }
}
