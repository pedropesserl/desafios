#include <bits/stdc++.h>
using namespace std;

#define OP(a, b) min(a, b)
#define NEUTRAL 1987654321987654321
#define FACTOR(fac) 1

int n;

vector<long> t, lazy, sety;

void build(vector<long>& src, int ti = 1, int tl = 1, int tr = n) {
    if (tl == tr) {
        if (tl < src.size()) {
            t[ti] = src[tl];
        }
        return;
    }
    int tm = (tl + tr) / 2;
    build(src, ti * 2, tl, tm);
    build(src, ti * 2 + 1, tm + 1, tr);
    t[ti] = OP(t[ti * 2], t[ti * 2 + 1]);
}

void push(int ti, int tl, int tm, int tr) {
    if (sety[ti] != -1) {
        t[ti * 2] = sety[ti] * FACTOR(tm - tl + 1);
        lazy[ti * 2] = 0;
        sety[ti * 2] = sety[ti];
        t[ti * 2 + 1] = sety[ti] * FACTOR(tr - (tm + 1) + 1);
        lazy[ti * 2 + 1] = 0;
        sety[ti * 2 + 1] = sety[ti];
        sety[ti] = -1;
    }
    t[ti * 2] += lazy[ti] * FACTOR(tm - tl + 1);
    lazy[ti * 2] += lazy[ti];
    t[ti * 2 + 1] += lazy[ti] * FACTOR(tr - (tm + 1) + 1);
    lazy[ti * 2 + 1] += lazy[ti];
    lazy[ti] = 0;
}

void add_inclusive(int l, int r, long delta, int ti = 1, int tl = 1, int tr = n) {
    if (l > r) {
        return;
    }
    if (tl == l && tr == r) {
        t[ti] += delta * FACTOR(tr - tl + 1);
        lazy[ti] += delta;
        return;
    }
    int tm = (tl + tr) / 2;
    push(ti, tl, tm, tr);
    add_inclusive(l, min(r, tm), delta, ti * 2, tl, tm);
    add_inclusive(max(l, tm + 1), r, delta, ti * 2 + 1, tm + 1, tr);
    t[ti] = OP(t[ti * 2], t[ti * 2 + 1]);
}

long op_inclusive(int l, int r, int ti = 1, int tl = 1, int tr = n) {
    if (l > r) {
        return NEUTRAL;
    }
    if (l <= tl && tr <= r) {
        return t[ti];
    }
    int tm = (tl + tr) / 2;
    push(ti, tl, tm, tr);
    return OP(op_inclusive(l, min(r, tm), ti * 2, tl, tm),
              op_inclusive(max(l, tm + 1), r, ti * 2 + 1, tm + 1, tr));
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int q, op, i, j, k;
    cin >> n >> q;

    vector<long> vetor(n + 1);
    t.resize(4 * n);
    lazy.resize(4 * n, 0);
    sety.resize(4 * n, -1);
    
    for (int it = 1; it <= n; it++) {
        cin >> vetor[it];
    }
    build(vetor);
    while (q--) {
        cin >> op;
        if (op == 1) {
            cin >> i >> j >> k;
            add_inclusive(i, j, k);
        } else { // op == 2
            cin >> i >> j;
            cout << op_inclusive(i, j) << "\n";
        }
    }

    return 0;
}
