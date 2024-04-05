#include <bits/stdc++.h>
using namespace std;

vector<vector<size_t>> dp(3, vector<size_t>(112345, numeric_limits<size_t>::max()));
vector<size_t> a(112345), b(112345), c(112345);
size_t n;

size_t sol(int escolhido, size_t i) {
    if (i == n-1) {
        switch (escolhido) {
            case 0: return dp[0][i] = a[i];
            case 1: return dp[1][i] = b[i];
            case 2: return dp[2][i] = c[i];
        }
    }
    switch (escolhido) {
        case 0:
            if (dp[0][i] != numeric_limits<size_t>::max()) {
                return dp[0][i];
            }
            return dp[0][i] = a[i] + max(sol(1, i+1), sol(2, i+1));
        case 1:
            if (dp[1][i] != numeric_limits<size_t>::max()) {
                return dp[1][i];
            }
            return dp[1][i] = b[i] + max(sol(0, i+1), sol(2, i+1));
        case 2:
            if (dp[2][i] != numeric_limits<size_t>::max()) {
                return dp[2][i];
            }
            return dp[2][i] = c[i] + max(sol(0, i+1), sol(1, i+1));
    }
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    cin >> n;
    for (size_t i = 0; i < n; i++) {
        cin >> a[i] >> b[i] >> c[i];
    }

    cout << max(max(sol(0, 0), sol(1, 0)), sol(2, 0)) << "\n";

    return 0;
}
