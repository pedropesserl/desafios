#include <bits/stdc++.h>
using namespace std;

vector<bool> visitados(11234, false);
struct edge {
    int v;
    long w;
};
vector<vector<edge>> g(11234);
vector<long> dists(11234, numeric_limits<int>::max());
vector<vector<edge>> subg(11234); // grafo direcionado que tem 0 como sumidouro

long soma_pesos;
void dfs(int u) {
    if (visitados[u]) return;
    visitados[u] = true;
    for (auto [v, w] : subg[u]) {
        soma_pesos += w;
        dfs(v);
    }
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    soma_pesos = 0;
    int p, t, a, b;
    long l;
    cin >> p >> t;
    for (int i = 0; i < t; i++) {
        cin >> a >> b >> l;
        g[a].push_back({b, l});
        g[b].push_back({a, l});
    }

    // Dijkstra
    priority_queue<pair<long, int>, vector<pair<long, int>>,
                   greater<pair<long, int>>> q;
    dists[0] = 0;
    q.push({0, 0});
    while (!q.empty()) {
        auto [d, u] = q.top();
        q.pop();
        if (visitados[u]) {
            continue;
        }
        visitados[u] = true;
        for (auto [v, w] : g[u]) {
            if (dists[u] + w <= dists[v]) {
                if (dists[u] + w < dists[v]) {
                    // limpar lista de pais de v
                    vector<edge>().swap(subg[v]);
                }
                subg[v].push_back({u, w});
                dists[v] = dists[u] + w;
                q.push({dists[v], v});
            }
        }
    }

    visitados.assign(visitados.size(), false);
    dfs(p - 1);
    cout << 2 * soma_pesos << "\n";

    return 0;
}
