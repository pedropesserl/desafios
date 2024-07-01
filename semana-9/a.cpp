#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> rede(112345);
vector<int> visitados(112345, false);
set<pair<int, int>> cabos;
vector<pair<int, int>> quebrados;
vector<int> representantes(112345); // união-busca
int c;
vector<int> componentes_rev;

void dfs(int v) {
    visitados[v] = true;
    for (int u : rede[v]) {
        if (!visitados[u]) {
            dfs(u);
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
        cabos.insert({u, v});
    }
    for (int i = 0; i < k; i++) {
        int u, v;
        cin >> u >> v;
        quebrados.push_back({u, v});
        cabos.erase({u, v});
        cabos.erase({v, u});
    }
    for (auto [u, v] : cabos) {
        rede[u].push_back(v);
        rede[v].push_back(u);
    }

    for (int v = 1, c = 0; v <= n; v++) {
        if (!visitados[v]) {
            c++;
            dfs(v);
        }
    }
    componentes_rev.push_back(c);

    

    reverse(componentes_rev.begin(), componentes_rev.end());
    for (int n_componentes : componentes_rev) {
        cout << n_componentes << " ";
    }
    cout << "\n";

    return 0;
}
