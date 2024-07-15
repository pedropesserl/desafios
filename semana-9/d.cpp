#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int n, m;
    cin >> n >> m;
    map<string, vector<string>> g;
    for (int i = 0; i < m; i++) {
        string u, v;
        cin >> u >> v;
        g[u].push_back(v);
    }

    set<pair<int, deque<string>>> caminhos_mins; // dist, [caminho]

    for (auto [u, vizinhos] : g) {
        map<string, bool> visitados;
        visitados[u] = true;
        map<string, string> pai;
        pai[u] = "";

        queue<string> q;
        q.push(u);
        while (!q.empty()) {
            string v = q.front();
            q.pop();
            for (string w : g[v]) {
                if (!visitados[w]) {
                    visitados[w] = true;
                    pai[w] = v;
                    q.push(w);
                }
            }
        }
        
        for (auto [v, visitado] : visitados) {
            if (v != u) {
                // reconstrur caminho
                deque<string> caminho;
                caminho.push_front(v);
                string v_ = v; // C++????
                while (v_ != u) {
                    v_ = pai[v_];
                    caminho.push_front(v_);
                }
                caminhos_mins.insert({caminho.size() - 1, caminho});
            }
        }
    }

    int soma_caminhos = 0;
    for (auto [dist, caminho] : caminhos_mins) {
        soma_caminhos += dist;
    }
    cout << (double)soma_caminhos / caminhos_mins.size() << "\n";

    int caminho_mediano = caminhos_mins.size() / 2 - (caminhos_mins.size() % 2 == 0);
    auto it = caminhos_mins.begin();
    for (int i = 0; i < caminho_mediano; i++, it++);
    for (auto s : (*it).second) {
        cout << s << " ";
    }
    cout << "\n";

    return 0;
}
