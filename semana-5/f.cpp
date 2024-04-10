#include <bits/stdc++.h>
using namespace std;

vector<size_t> custos(2000);
vector<size_t> vendas(2000);
vector<size_t> trocas;

size_t min_custo() {
    
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    
    size_t n, i, m, p;
    cin >> n >> i >> m >> p;
    for (size_t k = 0; k < m; k++) {
        cin >> custos[k];
    }
    for (size_t k = 0; k < m; k++) {
        cin >> vendas[k];
    }


    if (trocas.empty()) {
        cout << "0\n";
        return 0;
    }
    for (size_t k = 0; k < trocas.size() - 1; k++) {
        cout << trocas[k] << " ";
    }
    cout << trocas[trocas.size() - 1] << "\n";
    return 0;
}
