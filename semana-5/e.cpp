#include <bits/stdc++.h>
using namespace std;

vector<long> a(11234, 0);
size_t n, c;

vector<vector<long>> dp(11234, vector<long>(11234, numeric_limits<long>::min()));

long sol(size_t ini, size_t k) {
    if (k * c + ini + 1 > n) {
        return 0;
    }
    if (dp[ini][k] != numeric_limits<long>::min()) {
        return dp[ini][k];
    }
    if (k == 0) { // terminou de posicionar os lapis
        return dp[ini][k] = accumulate(a.begin() + ini, a.begin() + n, 0);
    }
    return dp[ini][k] = max(sol(ini + c, k - 1), a[ini] + sol(ini + 1, k));
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    size_t k;
    cin >> n >> k >> c;
    for (size_t i = 0; i < n; i++) {
        cin >> a[i];
    }

    cout << sol(0, k) << "\n";

    return 0;
}
