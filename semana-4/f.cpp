#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int n;
    cin >> n;
    vector<long> ps(n);
    for (int i = 0; i < n; i++) {
        cin >> ps[i];
    }

    sort(ps.begin(), ps.end());

    long t = ps[n / 2];
    size_t cont = 0;
    for (long p : ps) {
        cont += abs(p - t);
    }

    cout << cont << "\n";

    return 0;
}
