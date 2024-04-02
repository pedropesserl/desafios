#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0)->sync_with_stdio(0);

    size_t n;
    cin >> n;
    vector<string> a(n);
    for (size_t i = 0; i < n; i++) {
        cin >> a[i];
    }
    
    sort(a.begin(), a.end(), [](string s, string r) { return s + r < r + s; });

    for (string s : a) {
        cout << s;
    }
    cout << "\n";

    return 0;
}
