#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> g(11234);

int main() {
    // o número de arcos a serem construídos para que o grafo seja
    // fortemente conexo é igual ao número de sumidouros no grafo
    // condensado

    cin.tie(0)->sync_with_stdio(0);

    int n, m, r, s;
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        cin >> r >> s;
        g[r].push_back(s);
    }
    
    return 0;
}
