#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0)->sync_with_stdio(0);

    size_t n;
    cin >> n;

    set<int> rodadas;

    for (size_t i = 0; i < n; i++) {
        int x;
        cin >> x;
        if (rodadas.find(x - 1) != rodadas.end()) {
            rodadas.erase(x - 1);
        }
        rodadas.insert(x);
    }

    cout << rodadas.size() << "\n";

    return 0;
}
