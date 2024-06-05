#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> t(212345);
vector<bool> visitados(212345, false);

long size(int v) {
    visitados[v] = true;
    long sz = 1;
    for (int u : t[v]) {
        if (!visitados[u]) {
            sz += size(u);
        }
    }
    return sz;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int n;
    cin >> n;
    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        t[u].push_back(v);
        t[v].push_back(u);
    }

    if (n <= 2) {
        cout << "1\n";
        return 0;
    }
    
    int v = 1;
    long tamanho_ja_explorado = 0;
    int vizinho_ja_explorado;
    while (true) {
        visitados[v] = true;
        long max_size = 1;
        int vizi_max_size = v;
        if (tamanho_ja_explorado > max_size) {
            max_size = tamanho_ja_explorado;
            vizi_max_size = vizinho_ja_explorado;
        }
        for (int u : t[v]) {
            int u_size = size(u);
            if (u_size > max_size) {
                max_size = u_size;
                vizi_max_size = u;
            }
            tamanho_ja_explorado += u_size;
        }
        tamanho_ja_explorado += 1 - max_size;
        if (max_size <= n/2) {
            cout << v << "\n";
            break;
        }
        visitados.assign(visitados.size(), false);
        visitados[v] = true; // impede de procurar de novo na área que já buscamos
        v = vizi_max_size;
    }

    return 0;
}
