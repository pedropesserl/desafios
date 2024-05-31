#include <bits/stdc++.h>
using namespace std;

int n, m, t;
int num_zeros;
vector<vector<int>> mapa(1010, vector<int>(1010, -1));
set<pair<int, int>> vao_mudar;
set<pair<int, int>> vao_mudar_prox;

bool vai_mudar(int i, int j) {
    if (i == 0 or j == 0) {
        return false;
    }
    int zeros = 0;
    if (mapa[i][j] == 1) {
        zeros += mapa[i - 1][j - 1] == 0;
        zeros += mapa[i - 1][j + 1] == 0;
        zeros += mapa[i + 1][j - 1] == 0;
        zeros += mapa[i + 1][j + 1] == 0;
    }
    zeros += mapa[i - 1][j] == 0;
    zeros += mapa[i][j - 1] == 0;
    zeros += mapa[i][j + 1] == 0;
    zeros += mapa[i + 1][j] == 0;
    return ((mapa[i][j] == 1 or mapa[i][j] == 2) and zeros >= 1)
         or (mapa[i][j] == 3 and zeros >= 2)
         or (mapa[i][j] == 4 and zeros >= 3);
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    cin >> n >> m >> t;
    num_zeros = 0;
    for (int i = 1; i <= n; i++) for (int j = 1; j <= m; j++) {
        cin >> mapa[i][j];
        if (mapa[i][j] == 0) {
            num_zeros++;
        }
    }

    for (int i = 1; i <= n; i++) for (int j = 1; j <= m; j++) {
        if (mapa[i][j] == 0) {
            for (int k = -1; k <= 1; k++) for (int l = -1; l <= 1; l++) {
                if (vai_mudar(i + k, j + l)) {
                    vao_mudar.insert(make_pair(i + k, j + l));
                }
            }
        }
    }
    vao_mudar_prox = vao_mudar;

    for (int i = 0; i < t; i++) {
        for (auto [i, j] : vao_mudar) {
            mapa[i][j] = 0;
            num_zeros++;
            vao_mudar_prox.erase(make_pair(i, j));
        }
        for (auto [i, j] : vao_mudar) {
            for (int k = -1; k <= 1; k++) for (int l = -1; l <= 1; l++) {
                if ((k != 0 or l != 0) and vai_mudar(i + k, j + l)) {
                    vao_mudar_prox.insert(make_pair(i + k, j + l));
                }
            }
        }
        vao_mudar = vao_mudar_prox;
    }

    cout << num_zeros << "\n";

    return 0;
}
