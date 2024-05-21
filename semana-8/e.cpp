#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> t(112345);
vector<bool> visitados(112345, false);

long nivel(long v) {
    visitados[v] = true;
    long nivel = 0;
    for (long u : t[v]) {
        if (!visitados[u]) {
            nivel = max(nivel, 1 + nivel(u));
        }
    }
    return nivel;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    long n;
    cin >> n;
    for (long i = 0; i < m; i++) {
        long u, v;
        cin >> u >> v;
        t[u].push_back(v);
        t[v].push_back(u);
    }
    vector<int> vizinhos_raiz = t[0];
    long diametro = 0;///////aaaaaa

    return 0;
}
