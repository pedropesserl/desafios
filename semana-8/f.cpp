#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> mapa(1010, vector<int>(1010));

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int n, m, t;
    cin >> n >> m >> t;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> mapa[i][j];
        }
    }
        
    return 0;
}
