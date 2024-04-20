#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    size_t n, a;
    cin >> n >> a;
    for (; n != 0 || a != 0; cin >> n >> a) {
        vector<size_t> tiras(n + 1);
        tiras[n] = 0; // facilitar na hora de calcular as seções
        for (size_t i = 0; i < n; i++) { cin >> tiras[i]; }
        size_t total = accumulate(tiras.begin(), tiras.end(), 0);
        if (a == total) {
            cout << ":D\n";
            continue;
        }
        if (a > total) {
            cout << "-.-\n";
            continue;
        }
        sort(tiras.rbegin(), tiras.rend());
        size_t secoes = 0;
        for (size_t i = 0; i < n; i++) {
            size_t secao = (tiras[i] - tiras[i + 1]) * (i + 1);
            if (secao == 0) { // tiras de mesma altura
                continue;
            }
            if (a - secoes <= secao) {
                double h = (double)tiras[i + 1] + (double)(secoes + secao - a) / (i + 1);
                cout << fixed << setprecision(4) << h << "\n";
                break;
            }
            secoes += secao;
        }
    }
    return 0;
}
