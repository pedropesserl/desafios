#include <bits/stdc++.h>
using namespace std;

#define M 1000000007

#define mod(a, b)  ((((a) % (b)) + (b)) % (b))
#define soma(a, b) (mod(mod(a, M) + mod(b, M), M))
#define mult(a, b) (mod(mod(a, M) * mod(b, M), M))
#define sub(a, b)  (mod(soma(mod(a, M) - mod(b, M), M), M))
long pot(long a, long b) {
    if (b == 0) {
        return 1;
    }
    if (b == 1) {
        return mod(a, M);
    }
    long res = pot(a, b / 2);
    res = mult(res, res);
    if (mod(b, 2) == 1) {
        res = mult(res, a);
    }
    return res;
}

int main() {
    long n;
    cin >> n;
    vector<long> primos(n), exps(n);
    for (long i = 0; i < n; i++) {
        cin >> primos[i] >> exps[i];
    }

    long n_divs = 1;
    for (long exp : exps) {
        n_divs = mult(n_divs, soma(exp, 1));
    }
    cout << n_divs << " ";

    long soma_divs = 1;
    for (long i = 0; i < n; i++) {
        soma_divs = mult(soma_divs, sub(pot(primos[i], soma(exps[i], 1)), 1) / sub(primos[i], 1));
    }
    cout << soma_divs << " ";

    long prod_divs = 1;
    if (n_divs % 2 == 1) { // quadrado perfeito
        long sqrt_numero = 1;
        for (long i = 0; i < n; i++) {
            sqrt_numero = mult(sqrt_numero, pot(primos[i], exps[i] / 2));
        }
        prod_divs = pot(mult(sqrt_numero, sqrt_numero), n_divs / 2) * sqrt_numero;
        cout << prod_divs << "\n";
        return 0;
    }
    for (long i = 0; i < n; i++) {
        prod_divs = mult(prod_divs, pot(pot(primos[i], exps[i]), n_divs / 2));
    }
    cout << prod_divs << "\n";
    return 0;
}
