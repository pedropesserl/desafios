#include <bits/stdc++.h>
using namespace std;

#define max3(a, b, c) (max(max((a), (b)), (c)))

void le_multiset(multiset<size_t> &m, size_t n, size_t limite) {
    for (size_t i = 0; i < n; i++) {
        size_t e;
        cin >> e;
        m.insert(e);
        if (m.size() > limite) {
            m.erase(m.begin());
        }
    }
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    size_t x, y, n_vermelhas, n_verdes, n_sem_cor, soma = 0;
    cin >> x >> y >> n_vermelhas >> n_verdes >> n_sem_cor;
    multiset<size_t> vermelhas, verdes, sem_cor; 
    le_multiset(vermelhas, n_vermelhas, x);
    le_multiset(verdes, n_verdes, y);
    le_multiset(sem_cor, n_sem_cor, -1);

    while (x > 0 && y > 0) {
        size_t sc = sem_cor.empty() ? 0 : *sem_cor.rbegin();
        size_t maior = max3(*vermelhas.rbegin(), *verdes.rbegin(), sc);
        soma += maior;
        if (maior == *vermelhas.rbegin()) { // comer maçã vermelha
            vermelhas.erase(--vermelhas.end());
            x--;
        } else if (maior == *verdes.rbegin()) { // comer maçã verde
            verdes.erase(--verdes.end());
            y--;
        } else { // comer maçã sem cor
            if (*vermelhas.begin() < *verdes.begin()) { // pintar maçã de vermelho
                vermelhas.erase(vermelhas.begin());
                x--;
            } else { // pintar maçã de verde
                verdes.erase(verdes.begin());
                y--;
            }
            sem_cor.erase(--sem_cor.end());
        }
    }
    while (x > 0) {
        size_t sc = sem_cor.empty() ? 0 : *sem_cor.rbegin();
        if (*vermelhas.rbegin() > sc) { // comer maçã vermelha
            soma += *vermelhas.rbegin();
            vermelhas.erase(--vermelhas.end());
        } else { // comer maçã sem cor
            vermelhas.erase(vermelhas.begin());
            soma += *sem_cor.rbegin();
            sem_cor.erase(--sem_cor.end());
        }
        x--;
    }
    while (y > 0) {
        size_t sc = sem_cor.empty() ? 0 : *sem_cor.rbegin();
        if (*verdes.rbegin() > sc) { // comer maçã verde
            soma += *verdes.rbegin();
            verdes.erase(--verdes.end());
        } else { // comer maçã sem cor
            verdes.erase(verdes.begin());
            soma += *sem_cor.rbegin();
            sem_cor.erase(--sem_cor.end());
        }
        y--;
    }

    cout << soma << "\n";

    return 0;
}
