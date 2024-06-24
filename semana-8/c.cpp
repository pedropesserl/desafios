#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> linhagem(112345);
vector<bool> visitados(112345, false);
vector<int> morreram;
vector<int> ordem;
vector<bool> vivos(112345, true);

void dfs(int v) {
    visitados[v] = true;
    ordem.push_back(v);
    for (int u : linhagem[v]) {
        if (!visitados[u]) {
            dfs(u);
        }
    }
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int q, t, x, id = 1;
    cin >> q;
    // ler linhagem completa
    for (int i = 0; i < q; i++) {
        cin >> t >> x;
        if (t == 1) {
            linhagem[x].push_back(++id);
            linhagem[id].push_back(x);
        } else /* t == 2 */ {
            morreram.push_back(x);
        }
    }
    
    dfs(1);
    int monarca_ptr = 0;
    for (int morto : morreram) {
        vivos[morto] = false;
        while (vivos[ordem[monarca_ptr]] == false) {
            monarca_ptr++;
        }
        cout << ordem[monarca_ptr] << "\n";
    }

    return 0;
}
