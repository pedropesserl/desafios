#include <bits/stdc++.h>
using namespace std;

vector<size_t> pratos(18);
vector<tuple<size_t, size_t, size_t>> regras(18*(18 - 1));

int main() {
    cin.tie(0)->sync_with_stdio(0);

    size_t n, m, k;
    cin >> n >> m >> k;

    for (size_t i = 0; i < n; i++) {
        cin >> pratos[i];
    }
    for (size_t i = 0; i < k; i++) {
        size_t prato_1, prato_2, satisfacao;
        cin >> prato_1 >> prato_2 >> satisfacao;
        regras[i] = make_tuple(prato_1, prato_2, satisfacao);
    }

    return 0;
}
