#include <bits/stdc++.h>
using namespace std;

vector<int> pre(string ne) {
    vector<int> pi (ne.size(), 0);
    for (int i = 1, j = 0; i < (int)ne.size(); i++) {
        while (j > 0 && ne[i] != ne[j]) {
            j = pi[j - 1];
        }
        if (ne[i] == ne[j]) {
            j++;
        }
        pi[i] = j;
    }
    return pi;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    string s;
    cin >> s;
    vector<int> pi = pre(s);
    vector<int> bordas;
    bordas.push_back(pi[s.size() - 1]);
    while (bordas[bordas.size() - 1] >= 2) {
        // maior borda da maior borda
        bordas.push_back(pi[bordas[bordas.size() - 1] - 1]);
    }
    reverse(bordas.begin(), bordas.end());
    for (int borda : bordas) if (borda != 0) {
        cout << borda << " ";
    }
    cout << "\n";

    return 0;
}
