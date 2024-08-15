#include <bits/stdc++.h>
using namespace std;

#define N 11234

vector<int> vis (N); int cts = 1;
vector<vector<int>> g (N);
vector<set<int>> cg (N);

int tk = 1; vector<int> tin (N, -1), low (N);
stack<int> st; vector<int> rep (N), onst (N);

void dfs_tarjan(int u) {
    if (tin[u] != -1) {
        return;
    }
    tin[u] = low[u] = onst[u] = ++tk;
    st.push(u);
    for (int v : g[u]) {
        dfs_tarjan(v);
        if (onst[v]) {
            low[u] = min(low[u], low[v]);
        }
    }
    if (low[u] == tin[u]) {
        int v;
        do {
            v = st.top();
            st.pop();
            onst[v] = 0;
            rep[v] = u;
        } while (u != v);
    }
}

void tarjan(int n) {
    for (int u = 0; u < n; u++) {
        dfs_tarjan(u);
    }
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int n, m;
    cin >> n >> m;
    while (m--) {
        int u, v;
        cin >> u >> v;
        u--;
        v--;
        g[u].push_back(v);
    }

    tarjan(n);

    vector<int> vizinhos_de_entrada(n, 0);

    for (int u = 0; u < n; u++) {
        for (int v : g[u]) {
            if (rep[u] != rep[v]) {
                cg[rep[u]].insert(rep[v]);
                vizinhos_de_entrada[rep[v]]++;
            }
        }
    }
    int sumidouros = 0;
    int fontes = 0;
    int num_componentes = 0;
    for (int u = 0; u < n; u++) {
        if (rep[u] == u) {
            num_componentes++;
            if (cg[u].empty()) { // sumidouro
                sumidouros++;
            }
            if (vizinhos_de_entrada[u] == 0) { // fonte
                fontes++;
            }
        }
    }

    if (num_componentes == 1) {
        cout << "0\n";
    } else {
        cout << max(fontes, sumidouros) << "\n";
    }

    return 0;
}
