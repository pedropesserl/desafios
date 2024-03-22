#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int n;
    cin >> n;
    vector<int> ws(n);
    for (int i = 0; i < n; i++) {
        cin >> ws[i];
    }

    size_t diff = -1;
    for (size_t i = 0; i < (size_t)(1 << n); i++) {
        vector<int> p1, p2;
        for (int j = 0; j < n; j++) {
            if ((i >> j) & 1) {
                p1.push_back(ws[j]);
            } else {
                p2.push_back(ws[j]);
            }
        }
        size_t d = abs(accumulate(p1.begin(), p1.end(), 0) - accumulate(p2.begin(), p2.end(), 0));
        if (d < diff) {
            diff = d;
        }
    }

    cout << diff << "\n";

    return 0;
}
