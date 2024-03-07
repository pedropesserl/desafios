#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0)->sync_with_stdio(0);

    size_t n;
    cin >> n;
    vector<size_t> v(n, 0);
    for (size_t i = 0; i < n; i++) { cin >> v[i] }

    int rodadas = 1;
    // nao é isso
    /* for (size_t i = 0; i < n-1; i++) { */
    /*     if (v[i] >= v[i+1]) { */
    /*         rodadas++; */
    /*     } */
    /* } */
    // 1 2 3 5 4 7 6 isso daria 3 mas so precisa de 2 rodadas
    // 1 3 2 5 4 7 6 isso daria 4 mas so precisa de 2 rodadas

    vector<int> sequencias;

    return 0;
}
