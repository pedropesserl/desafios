#include <bits/stdc++.h>
using namespace std;

vector<set<int>> rede(112345); // o grafo é um vetor de set para poder
                               // remover conexões em log n
vector<bool> visitados(112345, false);
vector<int> indices_componentes(112345, -1);

vector<set<int>> componentes;
void dfs(int v, int i) {
    visitados[v] = true;
    componentes[i].insert(v);
    indices_componentes[v] = i;
    for (int u : rede[v]) {
        if (!visitados[u]) {
            dfs(u, i);
        }
    }
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int n, m, k;
    cin >> n >> m >> k;
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        rede[u].insert(v);
        rede[v].insert(u);
    }

    for (int v = 1, i = 0; v <= n; v++) {
        if (!visitados[v]) {
            componentes.push_back({v});
            dfs(v, i++);
        }
    }

    for (int i = 0; i < k; i++) {
        int u, v;
        cin >> u >> v;
        rede[u].erase(v);
        rede[v].erase(u);
        // atualizar componentes
    }

    cout << componentes.size() << "\n";
    for (auto componente : componentes) {
        for (auto v : componente) {
            cout << v << "(" << indices_componentes[v] << ") ";
        }
        cout << "\n";
    }

    return 0;
}
