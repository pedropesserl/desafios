#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0)->sync_with_stdio(0);

    list<int> fita;
    list<int>::iterator it = fita.begin();

    size_t n;
    cin >> n;
    for (size_t i = 0; i < n; i++) {
        char op;
        cin >> op;
        switch (op) {
            case 'm':
                int d;
                cin >> d;
                advance(it, d);
                break;
            case 'i':
                int q, t;
                cin >> q >> t;
                for (int j = 0; j < q; j++) {
                    fita.insert(it, t);
                    it--;
                }
                break;
            case 'd':
                {
                    // se não copiar o iterador antes de apagar, perde a referencia
                    list<int>::iterator copia_it = it;
                    it++;
                    fita.erase(copia_it);
                }
                break;
            case 'q':
                cout << *it << "\n";
                break;
            default:
                break;
        }
    }

    return 0;
}
