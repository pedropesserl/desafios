#include <bits/stdc++.h>
using namespace std;

size_t sol(int alvo, size_t tam, vector<int> moedas) {
    if (alvo < 0) {
        return 0;
    }
    if (alvo == 0) {
        return 1;
    }
    if (tam == 0) {
        return 0;
    }
    return sol(alvo, tam - 1, moedas) + sol(alvo - moedas[tam-1], tam, moedas);
}

int main() {
    /* cin.tie(0)->sync_with_stdio(0); */

    vector<int> moedas = {1, 5, 10, 25, 50};

    int n;
    while (cin >> n) {
        cout << sol(n, 5, moedas) << "\n";
    }
    
    return 0;
}
