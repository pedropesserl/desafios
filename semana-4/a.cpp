#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0)->sync_with_stdio(0);

    long t;
    cin >> t;
    for (long i = 0; i < t; i++) {
        long p, h, f, d, c, lucro = 0;
        cin >> p >> h >> f >> d >> c;
        if (p % 2 == 1) {
            p--;
        }
        if (p == 0) {
            cout << "0\n";
            continue;
        }
        if (d > c) {
            if (p <= 2 * h) {
                lucro = d * p / 2;
            } else {
                lucro = d * h;
                p -= 2 * h;
                if (p <= 2 * f) {
                    lucro += c * p / 2;
                } else {
                    lucro += c * f;
                }
            }
        } else {
            if (p <= 2 * f) {
                lucro = c * p / 2;
            } else {
                lucro = c * f;
                p -= 2 * f;
                if (p <= 2 * h) {
                    lucro += d * p / 2;
                } else {
                    lucro += d * h;
                }
            }
        }
        cout << lucro << "\n";
    }

    return 0;
}
