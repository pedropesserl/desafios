#include <bits/stdc++.h>
using namespace std;

vector<vector<size_t>> dp(3, vector<size_t>(112345, numeric_limits<size_t>::max()));
vector<vector<size_t>> atividades(3, vector<size_t>(112345));
size_t n;

size_t sol(int e, size_t i) {
    if (i == n-1) {
        return dp[e][i] = atividades[e][i];
    }
    if (dp[e][i] != numeric_limits<size_t>::max()) {
        return dp[e][i];
    }
    switch (e) {
        case 0: return dp[0][i] = atividades[0][i] + max(sol(1, i+1), sol(2, i+1));
        case 1: return dp[1][i] = atividades[1][i] + max(sol(0, i+1), sol(2, i+1));
        case 2: return dp[2][i] = atividades[2][i] + max(sol(0, i+1), sol(1, i+1));
    }
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    cin >> n;
    for (size_t i = 0; i < n; i++) {
        cin >> atividades[0][i] >> atividades[1][i] >> atividades[2][i];
    }

    cout << max(max(sol(0, 0), sol(1, 0)), sol(2, 0)) << "\n";

    return 0;
}
