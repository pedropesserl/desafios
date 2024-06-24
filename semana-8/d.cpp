#include <bits/stdc++.h>
using namespace std;

vector<vector<long>> t(212345);
vector<bool> visitados(212345, false);
long mais_distante;
long maior_dist;

void dfs(long v, long dist) {
    visitados[v] = true;
    if (dist > maior_dist) {
        maior_dist = dist;
        mais_distante = v;
    }
    for (long u : t[v]) {
        if (!visitados[u]) {
            dfs(u, dist + 1);
        }
    }
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    long n;
    cin >> n;
    for (long i = 0; i < n - 1; i++) {
        long u, v;
        cin >> u >> v;
        t[u].push_back(v);
        t[v].push_back(u);
    }
    
    dfs(1, 0);
    visitados.assign(visitados.size(), false);
    maior_dist = 0;
    dfs(mais_distante, 0);
    cout << maior_dist << "\n";

    return 0;
}
