#include <bits/stdc++.h>
using namespace std;



int main() {
    cin.tie(0)->sync_with_stdio(0);

    size_t n, k, c;
    cin >> n >> k >> c;
    vector<long> a(n);
    for (long i = 0; i < n; i++) {
        cin >> a[i];
    }

    long total = accumulate(a.begin(), a.end(), 0);

    return 0;
}
