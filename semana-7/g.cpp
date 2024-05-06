#include <bits/stdc++.h>
using namespace std;

#define M 1000000007

#define mult(a, b) (((a % M) * (b % M)) % M)
#define divi(a, b) (mult(a, pot(b, M - 2)))
long pot(long a, long b) {
    if (b == 0) {
        return 1;
    }
    if (b == 1) {
        return a % M;
    }
    long res = pot(a, b / 2);
    res = mult(res, res);
    if (b % 2 == 1) {
        res = mult(res, a);
    }
    return res;
}

vector<size_t> fat(11234, 1);

int main() {
    cin.tie(0)->sync_with_stdio(0);

    for (size_t i = 0; i < 10000; i++) {
        fat[i + 1] = mult(fat[i], i + 1);
    }

    size_t n, c;
    cin >> n >> c;
    vector<pair<size_t, size_t>> colunas(n, make_pair(0, n)); // #bolas, #casas disponíveis
    for (size_t i = 0; i < n; i++) {
        cin >> colunas[i].first;
    }
    for (size_t i = 0; i < c; i++) {
        size_t lin, col;
        cin >> lin >> col;
        (colunas[col - 1].second)--;
    }

    size_t res = 1;
    for (size_t i = 0; i < n; i++) {
        // arranjo de `colunas[i].first` escolhendo `colunas[i].second`
        res = mult(res, divi(fat[colunas[i].first], fat[colunas[i].first - colunas[i].second]));
    }

    cout << res << "\n";

    return 0;
}
