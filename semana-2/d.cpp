#include <bits/stdc++.h>
using namespace std;
using u64 = unsigned long;

typedef struct arq {
    u64 utils;
    int tipo;
    size_t tamanho;
} Arq;

bool compara_arqs(Arq a, Arq b) {
    if (a.utils == b.utils) {
        if (a.tipo == b.tipo) {
            return a.tamanho < b.tamanho;
        }
        return a.tipo > b.tipo;
    }
    return a.utils > b.utils;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    u64 n, k;
    cin >> n >> k;

    priority_queue<Arq, vector<Arq>, bool (*)(Arq a, Arq b)> arquivos(compara_arqs);
    for (u64 i = 0; i < n; i++) {
        string tipo;
        Arq a = {0, 0, 0};
        cin >> a.utils >> tipo >> a.tamanho;
        if (tipo == "TMP") {
            a.tipo = 1;
        } else if (tipo == "OGG") {
            a.tipo = 2;
        } else if (tipo == "CPP") {
            a.tipo = 3;
        }
        arquivos.push(a);
    }

    size_t bytes_liberados = 0;
    for (u64 i = 0; i < k; i++) {
        bytes_liberados += arquivos.top().tamanho;
        arquivos.pop();
    }
    
    cout << bytes_liberados << "\n";

    return 0;
}
