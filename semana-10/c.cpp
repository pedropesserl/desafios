#include <bits/stdc++.h>
using namespace std;

#define N 112345
#define OP(a, b) (a) + (b)
#define NEUTRAL 0

vector<long> t(4 * N);
vector<bool> mark(4 * N);

void build(vector<long>& src, int ti = 1, int tl = 1, int tr = N) {
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

void push(int ti) {
    if (mark[ti]) {
        t[ti * 2] = t[ti * 2 + 1] = t[ti];
        mark[ti * 2] = mark[ti * 2 + 1] = true;
        mark[ti] = false;
    }
}

void set_inclusive(int l, int r, long value, int ti = 1, int tl = 1, int tr = N) {
    if (l > r) {
        return;
    }
    if (tl == l && tr == r) {
        t[ti] = value;
        mark[ti] = true;
        return;
    }
    push(ti);
    int tm = (tl + tr) / 2;
    set_inclusive(l, min(r, tm), value, ti * 2, tl, tm);
    set_inclusive(max(l, tm + 1), r, value, ti * 2 + 1, tm + 1, tr);
}

void add_inclusive(int l, int r, long delta, int ti = 1, int tl = 1, int tr = N) {
    if (l > r) {
        return;
    }
    if (tl == l && tr == r) {
        t[ti] += delta;
        return;
    }
    int tm = (tl + tr) / 2;
    add_inclusive(l, min(r, tm), delta, ti * 2, tl, tm);
    add_inclusive(max(l, tm + 1), r, delta, ti * 2 + 1, tm + 1, tr);
}

long op_inclusive(int l, int r, int ti = 1, int tl = 1, int tr = N) {
    if (l > r) {
        return NEUTRAL;
    }
    if (tl == l && tr == r) {
        return t[ti];
    }
    int tm = (tl + tr) / 2;
    return OP(op_inclusive(l, min(r, tm), ti * 2, tl, tm),
              op_inclusive(max(l, tm + 1), r, ti * 2 + 1, tm + 1, tr));
}

int main() {
    /* cin.tie(0)->sync_with_stdio(0); */

    int n, q, op, a, b, x;
    cin >> n >> q;

    vector<long> vetor(n + 1);
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
