#include <bits/stdc++.h>
using namespace std;

size_t resultado = 0;

void solucao(size_t a, size_t b, size_t n, size_t i, vector<size_t> &escolhas, vector<size_t> &ps) {
    if (i == n) {
        size_t m = 1;
        size_t cont = 0;
        for (size_t j = 0; j < n; j++) {
            if (escolhas[j]) {
                m *= ps[j];
                cont++;
            }
        }
        if (cont == 0) {
            return;
        }
        if (cont % 2 == 1) {
            resultado -= b/m - (a-1)/m;
        } else {
            resultado += b/m - (a-1)/m;
        }
        return;
    }

    escolhas[i] = 0;
    solucao(a, b, n, i+1, escolhas, ps);
    escolhas[i] = 1;
    solucao(a, b, n, i+1, escolhas, ps);
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    size_t a, b, n;
    cin >> a >> b >> n;
    resultado = b - a + 1;
    vector<size_t> ps(n, 0);
    for (size_t i = 0; i < n; i++) {
        cin >> ps[i];
    }

    vector<size_t> escolhas(n, 0);
    solucao(a, b, n, 0, escolhas, ps);

    cout << resultado << "\n"; 

    return 0;
}
