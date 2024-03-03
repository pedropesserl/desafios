#include <bits/stdc++.h>
using namespace std;

#define llu long long unsigned

int main() {
    llu t;
    string x, y;
    cin >> t;
    for (llu i = 0; i < t; i++) {
        cin >> x >> y;
        int last_x = (int)x[x.size() - 1] - '0';
        int last_y = (int)y[y.size() - 1] - '0';
        printf((last_x + last_y) % 2 == 0 ? "PARCEIROS\n" : "NAO PARCEIROS\n");
    }
    return 0;
}
