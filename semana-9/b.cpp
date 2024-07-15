#include <bits/stdc++.h>
using namespace std;

struct aresta {
    int u, v;
    long w;
};
const long oo = 1987654321987654321;
vector<aresta> arestas;
vector<long> dists(11234, oo);

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int n, m;
    cin >> n;
    vector<long> lotacoes(n);
    for (auto& lotacao : lotacoes) {
        cin >> lotacao;
    }
    cin >> m;
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        arestas.push_back({u, v, lotacoes[v - 1] - lotacoes[u - 1]});
    }

    // Bellman-Ford
    dists[1] = 0;
    for (int i = 0; i < n - 1; i++) {
        for (aresta a : arestas) {
            if (dists[a.u] != oo && dists[a.v] > dists[a.u] + a.w) {
                dists[a.v] = dists[a.u] + a.w;
            }   
        }
    }

    int q;
    cin >> q;
    for (int i = 0; i < q; i++) {
        int x;
        cin >> x;
        if (dists[x] < 3 || dists[x] >= oo) {
            cout << "Não, Edsger...\n";
        } else {
            cout << dists[x] << "\n";
        }
    }

    return 0;
}
