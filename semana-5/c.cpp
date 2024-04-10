#include <bits/stdc++.h>
using namespace std;

vector<size_t> pratos(18);
vector<vector<size_t>> bonus (18, vector<size_t>(19, 0));
size_t npratos, ncomer, nregras;

size_t sol(size_t bitset, size_t comidos, size_t ultimo) {
    if (comidos == ncomer) {
        return 0;
    }
    size_t res = 0;
    for (size_t i = 0; i < npratos; i++) {
        if (!((bitset >> i) & 1)) {
            res = max(res, pratos[i] + bonus[i][ultimo] + sol(bitset | (1<<i), comidos + 1, i));
        }
    }
    return res;
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

    cout << sol(0, 0, npratos) << "\n";

    return 0;
}
