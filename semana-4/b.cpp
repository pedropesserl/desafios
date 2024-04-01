#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0)->sync_with_stdio(0);

    size_t n, l, d, litros = 0;
    cin >> n;

    map<size_t, multiset<size_t>> tempos;
    size_t maior_d = 0;
    for (size_t i = 0; i < n; i++) {
        cin >> l >> d;
        tempos[d].insert(l);
        if (tempos[d].size() > d) {
            tempos[d].erase(tempos[d].begin());
        }
        if (maior_d < d) {
            maior_d = d;
        }
    }
    
    multiset<size_t> candidatos;

    for (size_t i = 0; i < maior_d; i++) {
        for (auto& [k, v] : tempos) {
            auto elem = v.begin()
        }
    }

    cout << litros << "\n";

    return 0;
}
