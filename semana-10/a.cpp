#include <bits/stdc++.h>
using namespace std;

int n;

vector<int> merge(vector<int> a, vector<int> b) {
    vector<int> c(a.size() + b.size());
    size_t ai = 0, bi = 0, ci = 0;
    while (ai < a.size() && bi < b.size()) {
        if (a[ai] < b[bi]) {
            c[ci++] = a[ai++];
        } else {
            c[ci++] = b[bi++];
        }
    }
    while (ai < a.size()) {
        c[ci++] = a[ai++];
    }
    while (bi < b.size()) {
        c[ci++] = b[bi++];
    }
    return c;
}

vector<vector<int>> t;

void build(vector<int>& src, int ti = 1, int tl = 1, int tr = n) {
    if (tl == tr) {
        if ((size_t)tl < src.size()) {
            t[ti].push_back(src[tl]);
        }
        return;
    }
    int tm = (tl + tr) / 2;
    build(src, ti * 2, tl, tm);
    build(src, ti * 2 + 1, tm + 1, tr);
    t[ti] = merge(t[ti * 2], t[ti * 2 + 1]);
}

int op_inclusive(int l, int r, int x, int ti = 1, int tl = 1, int tr = n) {
    if (l > r) {
        return 0;
    }
    if (l == tl && tr == r) {
        return upper_bound(t[ti].begin(), t[ti].end(), x) - t[ti].begin();
    }
    int tm = (tl + tr) / 2;
    return op_inclusive(l, min(r, tm), x, ti * 2, tl, tm)
           + op_inclusive(max(l, tm + 1), r, x, ti * 2 + 1, tm + 1, tr);
}

int main() {
    /* cin.tie(0)->sync_with_stdio(0); */

    int q, i, j, k;
    cin >> n >> q;

    vector<int> vetor(n + 1);
    for (int it = 1; it <= n; it++) {
        cin >> vetor[it];
    }

    t.resize(4 * n);
    build(vetor);

    for (auto v : t) {
        if (v.empty()) continue;
        for (auto debug : v) {
            cout << debug << " ";
        }
        cout << "\n";
    }

    while (q--) {
        cin >> i >> j >> k;

        int hi = 1e9, lo = -1e9;
        /* while (hi > lo) { */
        /*     int m = (hi + lo) / 2; */
        /* } */

        auto res = op_inclusive(i, j, k);
        cout << res << "\n";

    }

    return 0;
}
