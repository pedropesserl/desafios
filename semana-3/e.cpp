#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int n;
    cin >> n;
    vector<int> s(n);
    for (int i = 0; i < n; i++) {
        cin >> s[i];
    }

    size_t cont = 0;

    map<int, size_t> esq;
    map<int, size_t> dir;

    for (int i : s) {
        for (int j : s) {
            for (int k : s) {
                esq[i * j + k]++;
                if (i != 0) {
                    dir[i * (j + k)]++;
                }
            }
        }
    }

    for (auto [k, v] : esq) {
        cont += v * dir[k];
    }

    cout << cont << "\n";
    
    return 0;
}
