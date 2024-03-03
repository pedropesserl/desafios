#include <bits/stdc++.h>
using namespace std;

int main() {
    int a, b, c;
    cin >> a >> b >> c;
    if (b == 0 || (a == 1 && b == 1)) {
        // 0 + 0 - c
        // 1 - 1 - c
        cout << -c << "\n";
    } else if (b == 1) {
        // 0 - 1 - c
        cout << -1 - c << "\n";
    } else {
        cout << a - b * c << "\n";
    }
}
