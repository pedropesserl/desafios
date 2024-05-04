#include <bits/stdc++.h>
using namespace std;

#define M 1000000007

#define mod(a, b)  ((((a) % (b)) + (b)) % (b))
#define soma(a, b) (mod(mod(a, M) + mod(b, M), M))
#define mult(a, b) (mod(mod(a, M) * mod(b, M), M))
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
long divi(long a, long b) { // a / b (mod M) == a * b^(-1) (mod M) == a * b^(M-2) (mod M)
    return mult(a, pot(b, M - 2));
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
    for (long exp : exps) {
        n_divs = mult(n_divs, exp + 1);
    }
    cout << n_divs << " ";

    long soma_divs = 1;
    for (long i = 0; i < n; i++) {
        soma_divs = mult(soma_divs, divi(pot(primos[i], exps[i] + 1) - 1, primos[i] - 1));
    }
    cout << soma_divs << " ";

    long prod_divs = 1;
    if (n_divs % 2 == 1) { // quadrado perfeito
        long sqrt_numero = 1;
        for (long i = 0; i < n; i++) {
            sqrt_numero = mult(sqrt_numero, pot(primos[i], exps[i] / 2));
        }
        prod_divs = pot(mult(sqrt_numero, sqrt_numero), divi(n_divs, 2));
        cout << prod_divs << "\n";
        return 0;
    }
    for (long i = 0; i < n; i++) {
        prod_divs = mult(prod_divs, pot(pot(primos[i], exps[i]), divi(n_divs, 2)));
    }
    cout << prod_divs << "\n";
    return 0;
}