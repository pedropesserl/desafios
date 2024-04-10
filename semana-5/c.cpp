#include <bits/stdc++.h>
using namespace std;

vector<size_t> pratos(18);
map<pair<size_t, size_t>, size_t> regras; // [prato 1, prato 2] -> satisfação
size_t npratos, ncomer, nregras;

// procurar todas as permutacoes do vetor a ser testado?
size_t soma_satisf(vector<size_t> prts) {
    if (prts.empty()) {
        return 0;
    }
    size_t soma = 0;
    for (size_t i = 0; i < prts.size() - 1; i++) {
        soma += prts[i];
        if (regras.find(make_pair(i+1, i+2)) != regras.end()) {
            soma += regras[make_pair(i+1, i+2)];
        }
    }
    soma += prts[prts.size() - 1];
    return soma;
}

// de npratos, escolhe k e checa as regras
size_t sol(size_t ini, vector<size_t> aux, size_t k) {
    if (k > npratos - ini) {
        return 0;
    }
    if (k == 0) { // achou combinação
        return soma_satisf(aux);
    }
    aux.push_back(pratos[ini]);
    size_t a = sol(ini + 1, aux, k - 1);
    aux.pop_back();
    size_t b = sol(ini + 1, aux, k);
    return max(a, b);
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    cin >> npratos >> ncomer >> nregras;
    for (size_t i = 0; i < npratos; i++) {
        cin >> pratos[i];
    }
    for (size_t i = 0; i < nregras; i++) {
        size_t p1, p2, satisfacao;
        cin >> p1 >> p2 >> satisfacao;
        regras[make_pair(p1, p2)] = satisfacao;
    }
    
    vector<size_t> aux;
    cout << sol(0, aux, ncomer) << "\n";

    return 0;
}
