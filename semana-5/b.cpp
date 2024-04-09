#include <bits/stdc++.h>
using namespace std;

vector<long> moedas(5);
vector<vector<long>> dp(6, vector<long>(31234, -1));

size_t sol(size_t tam, long alvo) {
    if (alvo < 0) {
        return 0;
    }
    if (tam == 0) {
        return dp[tam][alvo] = 0;
    }
    if (dp[tam][alvo] != -1) {
        return dp[tam][alvo];
    }
    if (alvo == 0) {
        return dp[tam][alvo] = 1;
    }
    return dp[tam][alvo] = sol(tam - 1, alvo) + sol(tam, alvo - moedas[tam-1]);
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    moedas = {1, 5, 10, 25, 50};

    long n;
    while (cin >> n) {
        cout << sol(5, n) << "\n";
    }
    
    return 0;
}
