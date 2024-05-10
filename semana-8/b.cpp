#include <bits/stdc++.h>
using namespace std;

vector<string> labirinto(1123);
vector<vector<bool>> visitados(1123, vector<bool>(1123, false));
string caminho;
vector<vector<long>> dp(1123, vector<long>(1123, -1));

long sol(int i, int j, string caminho_atual) {
    if (i < 0 or j < 0) {
        return -1;
    }
    if (dp[i][j] != -1) {
        return dp[i][j];
    }
    if (visitados[i][j] == true) {
        return -1;
    }
    if (labirinto[i][j] == '#') {
        return -1;
    }
    if (labirinto[i][j] == 'B') {
        if (caminho == "" or caminho_atual.size() < caminho.size()) {
            caminho = caminho_atual;
        }
        return dp[i][j] = 0;
    }
    visitados[i][j] = true;
    long ret = -1;
    long esq = sol(i, j - 1, caminho_atual + "L"), dir = sol(i, j + 1, caminho_atual + "R");
    long cim = sol(i - 1, j, caminho_atual + "U"), bai = sol(i + 1, j, caminho_atual + "D");
    if (esq != -1) { ret = 1 + esq; }
    if (dir != -1 and (ret == -1 or 1 + dir < ret)) { ret = 1 + dir; }
    if (cim != -1 and (ret == -1 or 1 + cim < ret)) { ret = 1 + cim; }
    if (bai != -1 and (ret == -1 or 1 + bai < ret)) { ret = 1 + bai; }
    visitados[i][j] = false;
    return dp[i][j] = ret;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int n, m;
    cin >> n >> m;
    int Ai = -1, Aj = -1;
    for (int i = 0; i < n; i++) {
        cin >> labirinto[i];
        if (Ai == -1) { // não achou início do labirinto ainda
            for (int j = 0; j < m; j++) {
                if (labirinto[i][j] == 'A') {
                    Ai = i;
                    Aj = j;
                    break;
                }
            }
        }
    }

    caminho = "";
    long tam = sol(Ai, Aj, "");
    if (tam == -1) {
        cout << "NO\n";
        return 0;
    }
    cout << "YES\n";
    cout << tam << "\n";
    cout << caminho << "\n";

    return 0;
}
