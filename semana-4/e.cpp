#include <bits/stdc++.h>
using namespace std;

// CASO ESPECIFICO: numero de macas verdes que temos que comer é maior que o
// numero de macas verdes disponiveis: nesse caso precisamos usar todas as macas
// sem cor possiveis para completar as macas verdes


void le_vetor(vector<long> &v) {
    for (size_t i = 0; i < v.size(); i++) {
        cin >> v[i];
    }
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int x, y, a, b, c;
    cin >> x >> y >> a >> b >> c;
    vector<long> p(a), q(b), r(c);
    le_vetor(p);
    le_vetor(q);
    le_vetor(r);

    sort(p.rbegin(), p.rend());
    sort(q.rbegin(), q.rend());
    sort(r.rbegin(), r.rend());
    
    long soma = 0;
    for (int i = 0, j = 0, k = 0; i < x or j < y;) {
        if (i < x and j < y and k < c) {
            if (p[i] > q[j]) {
                if (p[i] > r[k]) {
                    soma += p[i];
                } else {
                    soma += r[k];
                    k++;
                }
                i++;
            } else {
                if (q[j] > r[k]) {
                    soma += q[j];
                } else {
                    soma += r[k];
                    k++;
                }
                j++;
            }
            continue;
        }

        if (i < x and j < y and k == c) {
            if (p[i] > q[j]) {
                soma += p[i];
                i++;
            } else {
                soma += q[j];
                j++;
            }
        } else if (i < x and j == y and k < c) {
            if (p[i] > r[k]) {
                soma += p[i];
            } else {
                soma += r[k];
                k++;
            }
            i++;
        } else if (i == x and j < y and k < c) {
            if (q[j] > r[k]) {
                soma += q[j];
            } else {
                soma += r[k];
                k++;
            }
            j++;
        } else if (i < x and j == y) {
            soma += p[i];
            i++;
        } else if (i == x and j < y) {
            soma += q[j];
            j++;
        }
    }

    cout << soma << "\n";

    return 0;
}
