#include <bits/stdc++.h>
using namespace std;

const long oo = 1987654321987654321;

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int n, m;
    cin >> n >> m;
    vector<vector<long>> dists(n, vector<long>(n, oo));
    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        dists[u][v] = dists[v][u] = w;
    }
    
    // Floyd-Warshall
    for (int u = 0; u < n; u++) {
        dists[u][u] = 0;
    }
    for (int meio = 0; meio < n; meio++) {
        for (int u = 0; u < n; u++) {
            for (int v = 0; v < n; v++) {
                dists[u][v] = min(dists[u][v], dists[u][meio] + dists[meio][v]);
            }
        }
    }

    long min_dist_max = oo;
    for (int reuniao = 0; reuniao < n; reuniao++) {
        long dist_max = 0;
        for (int v = 0; v < n; v++) {
            dist_max = max(dist_max, dists[reuniao][v]);
        }
        min_dist_max = min(min_dist_max, dist_max);
    }

    cout << min_dist_max << "\n";

    return 0;
}
