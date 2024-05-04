#include <bits/stdc++.h>
using namespace std;

long pot(long a, long b) {
    if (b == 0) {
        return 1;
    }
    if (b == 1) {
        return a;
    }
    long res = pot(a, b / 2);
    res *= res;
    if (b % 2 == 1) {
        res *= a;
    }
    return res;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    long t;
    cin >> t;
    for (long i = 0; i < t; i++) {
        long n = 1, k, p, e;
        cin >> k;
        for (long j = 0; j < k; j++) {
            cin >> p >> e;
            n *= pot(p, e);
        }
        n--;
        vector<pair<long, long>> fatoracao;
        if (n % 2 == 0) {
            fatoracao.push_back(make_pair(2, 0));
        }
        while (n % 2 == 0) {
            n /= 2;
            (fatoracao[fatoracao.size() - 1].second)++;
        }
        for (long j = 3; j * j <= n; j += 2) {
            if (n % j == 0) {
                fatoracao.push_back(make_pair(j, 0));
            }
            while (n % j == 0) {
                n /= j;
                (fatoracao[fatoracao.size() - 1].second)++;
            }
        }
        if (n > 1) {
            fatoracao.push_back(make_pair(n, 1));
        }
        sort(fatoracao.begin(), fatoracao.end(),
             [](pair<long, long> a, pair<long, long> b) { return a.first > b.first; });
        for (auto par : fatoracao) {
            cout << par.first << " " << par.second << "\n";
        }

    }
    return 0;
}
