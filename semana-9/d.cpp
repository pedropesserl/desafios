#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0)->sync_with_stdio(0);

    const int oo = 987654321;
    int n, m;
    cin >> n >> m;

    map<string, int> ids;
    vector<string> strings(n + 10, "");
    int id = 1;

    vector<vector<int>> g(n + 10);
    for (int i = 0; i < m; i++) {
        string u, v;
        cin >> u >> v;
        if (ids[u] == 0) {
            ids[u] = id;
            strings[id++] = u;
        }
        if (ids[v] == 0) {
            ids[v] = id;
            strings[id++] = v;
        }
        g[ids[u]].push_back(ids[v]);
    }

    set<tuple<int, string, string>> caminhos_mins; // dist, origem, destino

    for (int u = 1; u <= n; u++) {
        vector<bool> visitados(n + 10, false);
        visitados[u] = true;
        vector<int> dists(n + 10, oo);
        dists[u] = 0;

        queue<int> q;
        q.push(u);
        while (!q.empty()) {
            int v = q.front();
            q.pop();
            for (int w : g[v]) {
                if (!visitados[w]) {
                    visitados[w] = true;
                    dists[w] = dists[v] + 1;
                    q.push(w);
                }
            }
        }
        
        for (int v = 1; v <= n; v++) {
            if (v != u && dists[v] != oo) {
                caminhos_mins.insert({dists[v], strings[u], strings[v]});
            }
        }
    }

    int soma_caminhos = 0;
    for (auto [dist, origem, destino] : caminhos_mins) {
        soma_caminhos += dist;
    }
    cout << (double)soma_caminhos / caminhos_mins.size() << "\n";

    int caminho_mediano = caminhos_mins.size() / 2 - (caminhos_mins.size() % 2 == 0);
    auto it = caminhos_mins.begin();
    for (int i = 0; i < caminho_mediano; i++, it++);

    int origem = ids[get<1>(*it)], destino = ids[get<2>(*it)];
    vector<bool> visitados(n + 10, false);
    visitados[origem] = true;
    vector<int> pai(n + 10, 0);
    queue<int> q;
    q.push(origem);
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (int v : g[u]) {
            if (!visitados[v]) {
                visitados[v] = true;
                pai[v] = u;
                q.push(v);
            }
        }
    }

    deque<string> caminho;
    for (int v = destino; v != 0; v = pai[v]) {
        caminho.push_front(strings[v]);
    }
    for (auto s : caminho) {
        cout << s << " ";
    }
    cout << "\n";

    return 0;
}
