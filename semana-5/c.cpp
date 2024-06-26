#include <bits/stdc++.h>
using namespace std;

vector<size_t> pratos(18);
vector<vector<size_t>> bonus(18, vector<size_t>(19, 0));
size_t npratos, ncomer, nregras;

vector<vector<size_t>> dp(19, vector<size_t>(1 << 18, numeric_limits<size_t>::max()));

size_t sol(size_t comidos, size_t ultimo, size_t bitset) {
    if (comidos == ncomer) {
        return dp[ultimo][bitset] = 0;
    }
    if (dp[ultimo][bitset] != numeric_limits<size_t>::max()) {
        return dp[ultimo][bitset];
    }
    size_t res = 0;
    for (size_t i = 0; i < npratos; i++) {
        if (!((bitset >> i) & 1)) {
            res = max(res, pratos[i] + bonus[i][ultimo] + sol(comidos + 1, i, bitset | (1<<i)));
        }
    }
    return dp[ultimo][bitset] = res;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    cin >> npratos >> ncomer >> nregras;
    for (size_t i = 0; i < npratos; i++) {
        cin >> pratos[i];
    }
    for (size_t i = 0; i < nregras; i++) {
        int p1, p2, satisfacao;
        cin >> p1 >> p2 >> satisfacao;
        p1--;
        p2--;
        bonus[p1][p2] = satisfacao;
    }

    cout << sol(0, npratos, 0) << "\n";

    return 0;
}
