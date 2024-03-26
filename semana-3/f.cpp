#include <bits/stdc++.h>
using namespace std;

size_t pg(vector<size_t> v) {
    if (v.size() <= 1) {
        return 0;
    }
    size_t q = v[1] / v[0];
    for (size_t i = 2; i < v.size(); i++) {
        if (v[i] / v[i - 1] != q) {
            return 0;
        }
    }
    return q;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int n;
    cin >> n;
    vector<size_t> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    sort(a.begin(), a.end());

    // testar o vetor completo
    if (size_t q = pg(a)) {
        if (q != 1 && a[0] % q == 0) {
            cout << a[0] / q << "\n";
        }
        cout << a[a.size() - 1] * q << "\n";
        return 0;
    }

    // buscar dois subvetores que estejam em progressão geométrica
    // e achar o número que uniria os dois
    
    // vetor menos 1 elemento da ponta esquerda
    {
        size_t a1 = a[0];
        vector<size_t> a2(n - 1);
        copy(a.begin() + 1, a.begin() + n, a2.begin());
        size_t q = pg(a2);
        if (q != 0) {
            cout << a1 * q << "\n";
            return 0;
        }
    }
    // vetor menos 1 elemento da ponta direita
    {
        vector<size_t> a1(n - 1);
        copy(a.begin(), a.begin() + n - 1, a1.begin());
        size_t q = pg(a1);
        if (q != 0) {
            cout << a1[a1.size() - 1] * q << "\n";
            return 0;
        }
    }

    for (int i = 2; i < n - 1; i++) {
        vector<size_t> a1(i);
        copy(a.begin(), a.begin() + i, a1.begin());
        vector<size_t> a2(n - i);
        copy(a.begin() + i, a.begin() + n, a2.begin());

        size_t q1 = pg(a1), q2 = pg(a2);
        if (q1 == q2 && q1 != 0) {
            cout << a1[a1.size() - 1] * q1 << "\n";
            return 0;
        }       
    }

    return 0;
}
