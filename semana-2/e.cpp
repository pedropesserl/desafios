#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int t;
    cin >> t;
    for (int i = 0; i < t; i++) {
        int l, n;
        cin >> l >> n;
        int maior_distancia_ao_fim = 0;
        int menor_distancia_ao_fim = l/2;
        for (int j = 0; j < n; j++) {
            int p;
            cin >> p;
            if (p > l/2) {
                p = l - p;
            }
            if (p < menor_distancia_ao_fim) {
                menor_distancia_ao_fim = p;
            }
            if (p > maior_distancia_ao_fim) {
                maior_distancia_ao_fim = p;
            }
        }
        cout << maior_distancia_ao_fim << " " << l - menor_distancia_ao_fim << "\n";
    }

    return 0;
}
