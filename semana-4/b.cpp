#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0)->sync_with_stdio(0);

    size_t n;
    cin >> n;
    vector<pair<size_t, size_t>> vacas(n); // litros de leite, paciência
    for (size_t i = 0; i < n; i++) {
        cin >> vacas[i].first >> vacas[i].second;
    }
    sort(vacas.begin(), vacas.end(),
            [](pair<size_t, size_t> a, pair<size_t, size_t> b){
                if (a.second == b.second) {
                    return a.first > b.first;
                }
                return a.second < b.second;
            }); // (2, 1), (1, 1), (3, 2), (1, 2), (8, 3), (5, 3), ...

    multiset<size_t> leites;
    for (size_t i = 0; i < n; i++) {
        if (leites.size() == vacas[i].second) {
            if (*leites.begin() < vacas[i].first) {
                leites.erase(leites.begin());
                leites.insert(vacas[i].first);
            }
        } else {
            leites.insert(vacas[i].first);
        }
    }

    cout << accumulate(leites.begin(), leites.end(), 0) << "\n";

    return 0;
}
