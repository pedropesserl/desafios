#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int n;
    cin >> n;
    vector<size_t> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    size_t min = -1;
    for (size_t i = 0; i < (size_t)(1 << (n-1)); i++) {
        // um bit 1 em i representa se devemos fazer uma divisão
        // e.g.: i =  0 0 1 0 1 0 1
        //       A = 1 2 3|4 5|6 7|8
        size_t _xor = 0, _or = a[0];
        for (int j = 0; j < n - 1; j++) {
            if (i >> (n - j - 2) & 1) {
                _xor ^= _or;
                _or = a[j+1];
            } else {
                _or |= a[j+1];
            }
        }
        _xor ^= _or;
        if (_xor < min) {
            min = _xor;
        }
    }

    cout << min << "\n";

    return 0;
}
