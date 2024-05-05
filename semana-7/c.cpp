#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0)->sync_with_stdio(0);

    size_t a, b, n;
    cin >> a >> b >> n;
    size_t resultado = b - a + 1;
    vector<size_t> xs(n);
    for (size_t i = 0; i < n; i++) {
        cin >> xs[i];
    }

    for (int escolhas = 1; escolhas < (1 << n); escolhas++) {
        size_t mmc;
        size_t count = 0;
        bool overflow = false;
        for (size_t i = 0; i < n; i++) {
            if ((escolhas >> i) & 1) {
                if (count == 0) {
                    mmc = xs[i];
                    count++;
                    continue;
                }
                if (mmc > numeric_limits<size_t>::max() / (xs[i] / gcd(mmc, xs[i]))) {
                    overflow = true;
                    break;
                }
                mmc = mmc * (xs[i] / gcd(mmc, xs[i]));
                count++;
            }
        }
        if (overflow) {
            continue;
        }
        if (count % 2 == 1) {
            resultado -= b/mmc - (a - 1)/mmc;
        } else {
            resultado += b/mmc - (a - 1)/mmc;
        }
    }

    cout << resultado << "\n"; 

    return 0;
}
