#include <bits/stdc++.h>
using namespace std;

vector<string> labirinto(1123);
vector<vector<bool>> visitados(1123, vector<bool>(1123, false));
vector<vector<long>> dists(1123, vector<long>(1123, numeric_limits<long>::max()));
vector<vector<char>> direcoes(1123, vector<char>(1123, '0'));

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int n, m;
    cin >> n >> m;
    int Ai = -1, Aj = -1, Bi = -1, Bj = -1;
    for (int i = 0; i < n; i++) {
        cin >> labirinto[i];
        if (Ai == -1 or Bi == -1) { // não achou início ou fim do labirinto ainda
            for (int j = 0; j < m; j++) {
                if (labirinto[i][j] == 'A') {
                    Ai = i;
                    Aj = j;
                }
                if (labirinto[i][j] == 'B') {
                    Bi = i;
                    Bj = j;
                }
            }
        }
    }

    // Dijkstra
    priority_queue<tuple<long, int, int>, vector<tuple<long, int, int>>,
                   greater<tuple<long, int, int>>> q;
    dists[Ai][Aj] = 0;
    q.push({0, Ai, Aj});
    while (!q.empty()) {
        auto [d, i, j] = q.top();
        q.pop();
        if (i == Bi and j == Bj) { // achou a saída
            break;
        }
        if (visitados[i][j]) {
            continue;
        }
        visitados[i][j] = true;
        vector<pair<int, int>> vizinhos = {{i - 1, j}, {i, j - 1}, {i, j + 1}, {i + 1, j}};
        for (auto [vi, vj] : vizinhos) {
            if (vi < 0 or vj < 0 or vi >= n or vj >= m or labirinto[vi][vj] == '#') {
                continue;
            }
            if (dists[vi][vj] > dists[i][j] + 1) {
                dists[vi][vj] = dists[i][j] + 1;
                q.push({dists[vi][vj], vi, vj});
                if      (vj == j - 1) direcoes[vi][vj] = 'L';
                else if (vj == j + 1) direcoes[vi][vj] = 'R';
                else if (vi == i - 1) direcoes[vi][vj] = 'U';
                else                  direcoes[vi][vj] = 'D';
            }
        }
    } 

    if (dists[Bi][Bj] == numeric_limits<long>::max()) {
        cout << "NO\n";
        return 0;
    }
    cout << "YES\n";
    cout << dists[Bi][Bj] << "\n";

    string caminho = "";
    for (pair<int, int> p = {Bi, Bj}; p.first != Ai or p.second != Aj;) {
        char d = direcoes[p.first][p.second];
        caminho += d;
        switch (d) {
            case 'L': p.second++; break;
            case 'R': p.second--; break;
            case 'U': p.first++;  break;
            case 'D': p.first--;  break;
        }
    }
    reverse(caminho.begin(), caminho.end());
    cout << caminho << "\n";

    return 0;
}
