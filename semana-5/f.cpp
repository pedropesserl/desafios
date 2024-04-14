#include <bits/stdc++.h>
using namespace std;

vector<size_t> custos(2000);
vector<size_t> vendas(2000);
vector<size_t> min_trocas(2000, numeric_limits<size_t>::max());
vector<size_t> trocas;
size_t idade_max, preco_nova;

size_t min_custo(size_t anos_prod, size_t idade) {
    if (anos_prod == 0) {
        if (trocas < min_trocas) {
            min_trocas = trocas;
        }
        return 0;
    }
    if (idade == idade_max) {
        trocas.push_back(idade);
        return -vendas[idade - 1] + preco_nova + custos[0] + min_custo(anos_prod - 1, 1); // substituir
    }
    trocas.push_back(idade);
    size_t ret = -vendas[idade - 1] + preco_nova + custos[0] + min_custo(anos_prod - 1, 1); // substituir
    trocas.pop_back();
    return min(ret, custos[idade] + min_custo(anos_prod - 1, idade + 1)); // não substituir
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    
    size_t anos_prod, idade;
    cin >> anos_prod >> idade >> idade_max >> preco_nova;
    for (size_t k = 0; k < idade_max; k++) {
        cin >> custos[k];
    }
    for (size_t k = 0; k < idade_max; k++) {
        cin >> vendas[k];
    }

    cout << min_custo(anos_prod, idade) << "\n";

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
