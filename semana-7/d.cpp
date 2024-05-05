#include <bits/stdc++.h>
using namespace std;

int main() {
    long n;
    cin >> n;
    vector<bool> sieve(n, true);
    for (long i = 2; i * i <= n; i++) {
        if (sieve[i]) {
            for (long j = i * i; j <= n; j += i) {
                sieve[j] = false;
            }
        }
    }
    long res = 0;
    for (long i = 2; i <= n/2; i++) {
        if (sieve[i] && sieve[n - i]) {
            res++;
        }
    }
    cout << res << "\n";
}
