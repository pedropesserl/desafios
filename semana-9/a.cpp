#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> rede(112345);

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int n, m, k;
    cin >> n >> m >> k;
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        rede[u].push_back(v);
        rede[v].push_back(u);
    }

    return 0;
}
