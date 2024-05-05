#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int t, n, d;
    cin >> t;
    for (int i = 0; i < t; i++) {
        cin >> n >> d;
        int parte_inteira = n / d;
        n -= d * parte_inteira;
        vector<int> fracoes;
        while (n != 0) {
            swap(n, d);
            int fracao = n / d;
            n -= d * fracao;
            fracoes.push_back(fracao);
        }
        cout << "[" << parte_inteira;
        if (fracoes.size() > 0) {
            cout << ";";
            for (size_t j = 0; j < fracoes.size() - 1; j++) {
                cout << fracoes[j] << ",";
            }
            cout << fracoes[fracoes.size() - 1];
        }
        cout << "]\n";
    }

    return 0;
}
