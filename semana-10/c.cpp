#include <bits/stdc++.h>
using namespace std;

#define OP(a, b) ((a) + (b))
#define NEUTRAL 0
#define FACTOR(fac) (fac)

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

void set_inclusive(int l, int r, long value, int ti = 1, int tl = 1, int tr = n) {
    if (l > r) {
        return;
    }
    if (tl == l && tr == r) {
        t[ti] = value * FACTOR(tr - tl + 1);
        sety[ti] = value;
        lazy[ti] = 0;
        return;
    }
    int tm = (tl + tr) / 2;
    push(ti, tl, tm, tr);
    set_inclusive(l, min(r, tm), value, ti * 2, tl, tm);
    set_inclusive(max(l, tm + 1), r, value, ti * 2 + 1, tm + 1, tr);
    t[ti] = OP(t[ti * 2], t[ti * 2 + 1]);
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

    int q, op, a, b, x;
    cin >> n >> q;

    vector<long> vetor(n + 1);
    t.resize(4 * n);
    lazy.resize(4 * n, 0);
    sety.resize(4 * n, -1);
    
    for (int i = 1; i <= n; i++) {
        cin >> vetor[i];
    }
    build(vetor);
    for (int i = 0; i < q; i++) {
        cin >> op;
        if (op == 1) {
            cin >> a >> b >> x;
            add_inclusive(a, b, x);
        } else if (op == 2) {
            cin >> a >> b >> x;
            set_inclusive(a, b, x);
        } else { // op == 3
            cin >> a >> b;
            cout << op_inclusive(a, b) << "\n";
        }
    }

    return 0;
}
