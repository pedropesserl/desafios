#include <bits/stdc++.h>
using namespace std;

#define M 1000000007

#define mod(a, b)  ((((a) % (b)) + (b)) % (b))
#define soma(a, b) (mod(mod(a, M) + mod(b, M), M))
#define sub(a, b)  (mod(mod(a, M) - mod(b, M) + M, M))
#define mult(a, b) (mod(mod(a, M) * mod(b, M), M))
#define divi(a, b) (mult(a, pot(b, M - 2)))
long pot(long a, long b) {
    if (b == 0) {
        return 1;
    }
    if (b == 1) {
        return mod(a, M);
    }
    long res = pot(a, b / 2);
    res = mult(res, res);
    if (b % 2 == 1) {
        res = mult(res, a);
    }
    return res;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    long n;
    cin >> n;
    vector<long> primos(n), exps(n);
    for (long i = 0; i < n; i++) {
        cin >> primos[i] >> exps[i];
    }

    long n_divs = 1;
    long n_divs_mod_m_menos_1 = 1;
    bool dividido_por_2 = false;
    for (long i = 0; i < n; i++) {
        n_divs = mult(n_divs, exps[i] + 1);

        if (!dividido_por_2 && (exps[i] + 1) % 2 == 0) {
            n_divs_mod_m_menos_1 = mod(mod(n_divs_mod_m_menos_1, M-1) * mod((exps[i] + 1) / 2, M-1), M-1);
            dividido_por_2 = true;
        } else {
            n_divs_mod_m_menos_1 = mod(mod(n_divs_mod_m_menos_1, M-1) * mod(exps[i] + 1, M-1), M-1);
        }
    }
    cout << n_divs << " ";

    long soma_divs = 1;
    for (long i = 0; i < n; i++) {
        soma_divs = mult(soma_divs, divi(sub(pot(primos[i], exps[i] + 1), 1), primos[i] - 1));
    }
    cout << soma_divs << " ";

    long prod_divs;
    if (!dividido_por_2) { // quadrado perfeito
        long sqrt_numero = 1;
        for (long i = 0; i < n; i++) {
            sqrt_numero = mult(sqrt_numero, pot(primos[i], exps[i] / 2));
        }
        prod_divs = pot(sqrt_numero, n_divs_mod_m_menos_1);
    } else {
        long numero = 1;
        for (long i = 0; i < n; i++) {
            numero = mult(numero, pot(primos[i], exps[i]));
        }
        prod_divs = pot(numero, n_divs_mod_m_menos_1);
    }
    cout << prod_divs << "\n";
    return 0;
}
