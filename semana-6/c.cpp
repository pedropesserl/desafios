#include <bits/stdc++.h>
using namespace std;

int main() {
    size_t n;
    cin >> n;
    multiset<size_t> topos;
    for (size_t i = 0; i < n; i++) {
        size_t cubo;
        cin >> cubo;
        auto it = topos.upper_bound(cubo);
        if (it != topos.end()) {
            topos.erase(it);
        }
        topos.insert(cubo);
    }
    cout << topos.size() << "\n";
    return 0;
}
