#include <bits/stdc++.h>
using namespace std;

vector<set<int>> rede(112345); // grafo é um vetor de set para poder excluir arestas em log n
vector<bool> visitados(112345, false);
vector<pair<int, int>> quebrados;
vector<int> representantes(112345); // união-busca
vector<int> ranks(112345);

int ds_find(int u) {
    if (representantes[u] != u) {
        representantes[u] = ds_find(representantes[u]);
    }
    return representantes[u];
}

void ds_union(int u, int v) {
    u = ds_find(u);
    v = ds_find(v);
    assert(u != v);
    if (ranks[u] <= ranks[v]) {
        swap(u, v);
    }
    if (ranks[u] == ranks[v]) {
        ranks[u]++;
    }
    representantes[v] = u;
}

void dfs(int u) {
    visitados[u] = true;
    for (int v : rede[u]) {
        if (!visitados[v]) {
            ds_union(u, v);
            dfs(v);
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
    for (int i = 0; i < k; i++) {
        int u, v;
        cin >> u >> v;
        quebrados.push_back({u, v});
        rede[u].erase(v);
        rede[v].erase(u);
    }

    // união-busca
    for (int u = 1; u <= n; u++) {
        representantes[u] = u;
        ranks[u] = 0;
    }

    int c = 0;
    for (int v = 1; v <= n; v++) {
        if (!visitados[v]) {
            c++;
            dfs(v);
        }
    }
    vector<int> componentes_rev;
    componentes_rev.push_back(c);

    reverse(quebrados.begin(), quebrados.end());
    for (auto [u, v] : quebrados) {
        if (ds_find(u) != ds_find(v)) {
            ds_union(u, v);
            c--;
        }
        componentes_rev.push_back(c);
    }

    for (int i = componentes_rev.size() - 2; i >= 0; i--) {
        cout << componentes_rev[i] << " ";
    }
    cout << "\n";

    return 0;
}
