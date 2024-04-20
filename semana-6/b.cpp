#include <bits/stdc++.h>
using namespace std;

int main() {
    size_t n, m;
    cin >> n >> m;
    multiset<size_t> precos;
    vector<size_t> fas(m);
    for (size_t i = 0; i < n; i++) {
        size_t preco;
        cin >> preco;
        precos.insert(preco);
    }
    for (size_t i = 0; i < m; i++) {
        cin >> fas[i];
    }

    for (size_t fa : fas) {
        if (precos.size() == 0) { // ingressos acabaram
            cout << "-1\n";
            continue;
        }
        auto it = precos.upper_bound(fa);
        if (it == precos.begin()) { // não consegue comprar
            cout << "-1\n";
            continue;
        }
        it--;
        cout << *it << "\n";
        precos.erase(it);
    }

    return 0;
}
