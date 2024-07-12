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
        arestas.push_back({u, v, lotacoes[v] - lotacoes[u]});
    }

    int q;
    cin >> q;
    for (int i = 0; i < q; i++) {
        dists.assign(dists.size(), oo);
        int x;
        cin >> x;
        // Bellman-Ford
        dists[1] = 0;
        for (int j = 0; j < n - 1; j++) {
            for (aresta a : arestas) {
                if (dists[a.u] != oo && dists[a.v] > dists[a.u] + a.w) {
                    dists[a.v] = dists[a.u] + a.w;
                }   
            }
        }
        if (dists[x] < 3) {
            cout << "Não, Edsger...\n";
        } else {
            cout << dists[x] << "\n";
        }
        /* // Verificação de ciclos negativos */
        /* for (auto a : arestas) */
    }

    return 0;
}
