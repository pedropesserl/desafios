#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0)->sync_with_stdio(0);

    const int P = 11234567;
    vector<bool> sieve(P, true);
    for (size_t i = 2; i <= P; i++) {
        if (sieve[i]) {
            for (size_t j = i * i; j <= P; j += i) {
                sieve[j] = false;
            }
        }
    }
    vector<size_t> primos;
    for (size_t i = 2; i <= P; i++) {
        if (sieve[i]) {
            primos.push_back(i);
        }
    }

    size_t t, n, k;
    cin >> t;
    for (size_t i = 0; i < t; i++) {
        cin >> n >> k;
        size_t produto = 1;
        for (size_t j = 0; j < k; j++) {
            produto *= primos[j];
        }
        size_t j = k;
        for (; j < primos.size() && produto <= n; j++) {
            produto /= primos[j - k];
            produto *= primos[j];
        }
        if (produto > n) {
            produto /= primos[j - 1];
            produto *= primos[j - k - 1];
        }
        cout << produto << "\n";
    }
    
    return 0;
}
