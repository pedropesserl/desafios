#include <bits/stdc++.h>
using namespace std;

map<size_t, size_t> dp; // n, f(n)

size_t f(size_t n) {
    if (dp.count(n) == 1) {
        return dp[n];
    }
    return dp[n] = f(n/2) + f(n/3);
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    size_t n;
    cin >> n;
    dp[0] = 1;
    cout << f(n) << "\n";
    return 0;
}
