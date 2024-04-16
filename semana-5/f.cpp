#include <bits/stdc++.h>
using namespace std;

vector<size_t> custos(2000);
vector<size_t> vendas(2000);
size_t idade_max, preco_nova;

vector<vector<size_t>> dp(2000+100, vector<size_t>(2000+100, numeric_limits<size_t>::max()));
vector<vector<size_t>> rec(2000+100, vector<size_t>(2000+100, numeric_limits<size_t>::max()));

int anos_prod;

size_t min_custo(size_t a, size_t idade) {
    if (a == anos_prod) {
        return dp[a][idade] = 0;
    }
    if (dp[a][idade] != numeric_limits<size_t>::max()) {
        return dp[a][idade];
    }
    if (idade == idade_max) {
        rec[a][idade] = 1;
        return dp[a][idade] = -vendas[idade - 1] + preco_nova + custos[0] + min_custo(a + 1, 1); // substituir
    }
    size_t ret = -vendas[idade - 1] + preco_nova + custos[0] + min_custo(a + 1, 1); // substituir
    size_t ret2 = custos[idade] + min_custo(a + 1, idade + 1); // não substituir
    if (ret <= ret2) {
        rec[a][idade] = 1;
    } else {
        rec[a][idade] = idade + 1;
    }
    return dp[a][idade] = min(ret, ret2);
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    
    size_t idade;
    cin >> anos_prod >> idade >> idade_max >> preco_nova;
    for (size_t k = 0; k < idade_max; k++) {
        cin >> custos[k];
    }
    for (size_t k = 0; k < idade_max; k++) {
        cin >> vendas[k];
    }

    cout << min_custo(0, idade) << "\n";
    bool printed = 0;
    for (size_t a = 0; a < anos_prod; a++) {
        if (rec[a][idade] == 1) {
            cout << a+1 << " ";
            printed = 1;
        }
        idade = rec[a][idade];
    }
    if (!printed) {
        cout << 0;
    }
    cout << "\n";
    return 0;
}
