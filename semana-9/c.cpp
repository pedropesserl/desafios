#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0)->sync_with_stdio(0);

    const int oo = 987654321;
    int n, m, c, k;
    cin >> n >> m >> c >> k;
    vector<vector<int>> dists(n, vector<int>(n, oo));
    for (int i = 0; i < m; i++) {
        int u, v, p;
        cin >> u >> v >> p;
        dists[u][v] = dists[v][u] = p;
    }
    for (int u = 0; u < n; u++) {
        dists[u][u] = 0;
    }

    // caminho_original[u] (0 <= u < c) descreve a distância de u a c - 1
    // no caminho original
    vector<int> caminho_original(c, 0);
    for (int u = c - 2; u >= 0; u--) {
        caminho_original[u] = caminho_original[u + 1] + dists[u][u + 1];
    }

    // Floyd-Warshall
    for (int w = 0; w < n; w++) {
        for (int u = 0; u < n; u++) {
            for (int v = 0; v < n; v++) {
                if (w < c) {
                    if (dists[u][v] > dists[u][w] + caminho_original[w]) {
                        dists[u][v] = dists[u][w] + caminho_original[w];
                    }
                } else {
                    if (dists[u][v] > dists[u][w] + dists[w][v]) {
                        dists[u][v] = dists[u][w] + dists[w][v];
                    }
                }
            }
        }
    }

    cout << dists[k][c - 1] << "\n";

    return 0;
}
