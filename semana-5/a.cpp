#include <bits/stdc++.h>
using namespace std;

/* vector<size_t> dp1(112345), dp2(112345), dp3(112345); */

size_t sol(vector<size_t> a, vector<size_t> b, vector<size_t> c, size_t i, int escolhido) {
    if (i == a.size() - 1) {
        switch (escolhido) {
            case 1: return a[i];
            case 2: return b[i];
            case 3: return c[i];
        }
    }
    switch (escolhido) {
        case 1: return a[i] + max(sol(a, b, c, i+1, 2), sol(a, b, c, i+1, 3));
        case 2: return b[i] + max(sol(a, b, c, i+1, 1), sol(a, b, c, i+1, 3));
        case 3: return c[i] + max(sol(a, b, c, i+1, 1), sol(a, b, c, i+1, 2));
    }
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    size_t n;
    cin >> n;
    vector<size_t> a(n), b(n), c(n);
    for (size_t i = 0; i < n; i++) {
        cin >> a[i] >> b[i] >> c[i];
    }

    /* dp1[0] = a[0]; */
    /* dp2[0] = b[0]; */
    /* dp3[0] = c[0]; */
    cout << max(max(sol(a, b, c, 0, 1), sol(a, b, c, 0, 2)), sol(a, b, c, 0, 3)) << "\n";

    return 0;
}
