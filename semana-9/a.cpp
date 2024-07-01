#include <bits/stdc++.h>
using namespace std;

vector<set<int>> rede(112345); // grafo é um vetor de set para poder remover
                               // conexões facilmente
vector<bool> visitados(112345, false);
const long oo = 1987654321987654321;
vector<long> dists(112345, oo);

void dfs(int v) {
    visitados[v] = true;
    for (int u : rede[v]) {
        if (!visitados[u]) {
            dfs(u);
        }
    }
}

long dijkstra(int u, int v) {
    dists.assign(dists.size(), oo);
    visitados.assign(visitados.size(), false);

    priority_queue<pair<long, int>, vector<pair<long, int>>,
                   greater<pair<long, int>>> q;
    dists[u] = 0;
    q.push({0, u});
    while (!q.empty()) {
        auto [d, a] = q.top();
        q.pop();
        if (visitados[a]) continue;
        visitados[a] = true;
        for (int b : rede[a]) {
            if (dists[b] > dists[a] + 1) {
                dists[b] = dists[a] + 1;
                q.push({dists[b], b});
            }
        }
    }

    return dists[v];
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

    int num_componentes = 0;
    for (int v = 1; v <= n; v++) {
        if (!visitados[v]) {
            num_componentes++;
            dfs(v);
        }
    }

    for (int i = 0; i < k; i++) {
        int u, v;
        cin >> u >> v;
        rede[u].erase(v);
        rede[v].erase(u);
        if (dijkstra(u, v) == oo) {
            num_componentes++;
        }
        cout << num_componentes << " ";
    }
    cout << "\n";
    
    return 0;
}
