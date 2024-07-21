#include <bits/stdc++.h>
using namespace std;

#define OP(a, b) merge(a, b)
#define NEUTRAL {}

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
    t[ti] = OP(t[ti * 2], t[ti * 2 + 1]);
}

vector<int> op_inclusive(int l, int r, int ti = 1, int tl = 1, int tr = n) {
    if (l > r) {
        return NEUTRAL;
    }
    if (l <= tl && tr <= r) {
        return t[ti];
    }
    int tm = (tl + tr) / 2;
    return OP(op_inclusive(l, min(r, tm), ti * 2, tl, tm),
              op_inclusive(max(l, tm + 1), r, ti * 2 + 1, tm + 1, tr));
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int q, i, j, k;
    cin >> n >> q;

    vector<int> vetor(n + 1);
    for (int it = 1; it <= n; it++) {
        cin >> vetor[it];
    }

    t.resize(4 * n);
    build(vetor);

    while (q--) {
        cin >> i >> j >> k;
        vector<int> res = op_inclusive(i, j);
        cout << res[k - 1] << "\n";
    }

    return 0;
}
