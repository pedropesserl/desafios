#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> t(212345);
vector<bool> visitados(212345, false);
vector<long> tamanhos(212345, 1);

void calcula_tamanho(int v) {
    visitados[v] = true;
    for (int u : t[v]) {
        if (!visitados[u]) {
            calcula_tamanho(u);
            tamanhos[v] += tamanhos[u];
        }
    }
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

    visitados[1] = true;
    long max_tam = 0;
    int v;
    for (int u : t[1]) {
        calcula_tamanho(u);
        if (tamanhos[u] > max_tam) {
            max_tam = tamanhos[u];
            v = u;
        }
    }
    int v_old = 1;
    while (max_tam > n/2) {
        tamanhos[v_old] = 0;
        for (int u : t[v_old]) {
            if (u != v) {
                tamanhos[v_old] += tamanhos[u];
            }
        }
        max_tam = 0;
        int v_next;
        for (int u : t[v]) {
            if (tamanhos[u] > max_tam) {
                max_tam = tamanhos[u];
                v_next = u;
            }
        }
        v_old = v;
        v = v_next;
    }
    cout << v_old << "\n";

    return 0;
}
