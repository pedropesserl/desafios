#include <bits/stdc++.h>
using namespace std;

int n;
void build(vector<int>& t, vector<int>& src, int ti = 1, int tl = 1, int tr = n) {
    if (tl == tr) {
        if (tl < src.size()) {
            t[ti] = src[tl];
        }
        return;
    }
    int tm = (tl + tr) / 2;
    build(t, src, ti * 2, tl, tm);
    build(t, src, ti * 2 + 1, tm + 1, tr);
    t[ti] = t[ti * 2] * t[ti * 2 + 1];
}

void set_value(vector<int>&t, int i, int v, int ti = 1, int tl = 1, int tr = n) {
    if (tl == tr) {
        t[ti] = v;
        return;
    }
    int tm = (tl + tr) / 2;
    if (i <= tm) {
        set_value(t, i, v, ti * 2, tl, tm);
    } else {
        set_value(t, i, v, ti * 2 + 1, tm + 1, tr);
    }
    t[ti] = t[ti * 2] * t[ti * 2 + 1];
}

int op_inclusive(vector<int>&t, int l, int r, int ti = 1, int tl = 1, int tr = n) {
    if (l > r) {
        return 1; // NEUTRAL
    }
    if (tl == l && tr == r) {
        return t[ti];
    }
    int tm = (tl + tr) / 2;
    return op_inclusive(t, l, min(r, tm), ti * 2, tl, tm) * op_inclusive(t, max(l, tm + 1), r, ti * 2 + 1, tm + 1, tr);
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int k, y, i, j, num;
    char c;
    cin >> n >> k;
    vector<int> sequencia(n + 1);
    vector<int> segtree(4 * n);
    for (int it = 1; it <= n; it++) {
        cin >> num;
        if (num > 0) {
            num = 1;
        } else if (num < 0) {
            num = -1;
        }
        sequencia[it] = num;
    }
    build(segtree, sequencia);
    for (int it = 0; it < k; it++) {
        cin >> c;
        if (c == 'A') {
            cin >> i >> y;
            if (y > 0) {
                y = 1;
            } else if (y < 0) {
                y = -1;
            }
            set_value(segtree, i, y);
        } else { // c == 'B'
            cin >> i >> j;
            int res = op_inclusive(segtree, i, j);
            if (res > 0) {
                cout << "+";
            } else if (res < 0) {
                cout << "-";
            } else {
                cout << "0";
            }
        }
    }
    cout << "\n";

    return 0;
}
