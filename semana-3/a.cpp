#include <bits/stdc++.h>
using namespace std;

bool restricoes_validas(vector<int> permutacao, vector<pair<int, int>> restricoes) {
    for (pair<int, int> restricao : restricoes) {
        for (int elem : permutacao) {
            // garante que o primeiro vem antes do segundo na permutação
            if (elem == restricao.first) {
                break;
            }
            if (elem == restricao.second) {
                return false;
            }
        }
    }
    return true;
}

void permutacoes(vector<int> v, vector<int> aux, int freq, vector<pair<int, int>> restricoes) {
    if (aux.size() == v.size()) {
        if (restricoes_validas(aux, restricoes)) {
            for (int j = 0; j < (int)aux.size() - 1; j++) {
                cout << aux[j] << " ";
            }
            cout << aux[aux.size() - 1] << "\n";
        }
        return;
    }

    for (int i = 0; i < (int)v.size(); i++) {
        if ((freq >> i) & 1) {
            continue; // bit 1 significa que já usamos essa posição
        }
        freq |= 1 << i; // ligar bit i
        aux.push_back(v[i]);
        if (!restricoes_validas(aux, restricoes)) {
            freq &= ~(1 << i); // desligar bit i
            aux.pop_back();
            continue; // pruning
        }
        permutacoes(v, aux, freq, restricoes);
        freq &= ~(1 << i); // desligar bit i
        aux.pop_back();
    }
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int n, c;
    cin >> n >> c;
    vector<pair<int, int>> restricoes(c);
    for (int i = 0; i < c; i++) {
        cin >> restricoes[i].first >> restricoes[i].second;
    }
    vector<int> livros(n);
    for (int i = 0; i < n; i++) {
        livros[i] = i + 1;
    }
    vector<int> aux;
    permutacoes(livros, aux, 0, restricoes);

    return 0;
}
