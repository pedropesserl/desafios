#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> g(1123);
vector<bool> visitados(1123, false);

void dfs(long v) {
    visitados[v] = true;
    for (long u : g[v]) {
        if (!visitados[u]) {
            dfs(u);
        }
    }
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    long n, m;
    cin >> n >> m;
    for (long i = 0; i < m; i++) {
        long u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    long festas = 0;
    for (long v = 0; v < n; v++) {
        if (!visitados[v]) {
            festas++;
            dfs(v);
        }
    }
    cout << festas << "\n";

    return 0;
}
