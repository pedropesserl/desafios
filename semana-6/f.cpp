#include <bits/stdc++.h>
using namespace std;

void add_bit(vector<long> &bit, long i, long delta) {
    for (; i < (long)bit.size(); i += i & -i)
        bit[i] += delta;
}

long get_bit(vector<long> &bit, long i) {
    long ans = 0;
    for (; i > 0; i -= i & -i)
        ans += bit[i];
    return ans;
}

long bs(vector<long> &bit, long a, long b, long x) {
    if (a > b) {
        return -1;
    }
    long m = a + (b - a)/2;
    long v = get_bit(bit, m);
    if (v < x) {
        return bs(bit, m + 1, b, x);
    }
    if (v == x && (m == 1 || x > get_bit(bit, m - 1))) { // primeira ocorrência
        return m;
    }
    return bs(bit, a, m - 1, x);
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    long n, q, d;
    char op;
    cin >> n >> q;
    vector<long> fita(n);
    vector<long> bit(n + 1, 1);
    bit[0] = bit[1] = 0;
    for (long i = 1; i <= n; i++) {
        long r = i + (i & -i);
        if (r <= n) {
            bit[r] += bit[i];
        }
    }

    for (long i = 0; i < n; i++) {
        cin >> fita[i];
    }

    long fita_sz = n;
    long idx = 0;
    for (long i = 0; i < q; i++) {
        cin >> op;
        if (op == 'm') {
            cin >> d;
            idx += d;
        } else if (op == 'd') {
            add_bit(bit, bs(bit, 1, n, idx), -1);
        } else { // op == 'q'
            cout << fita[bs(bit, 1, n, idx) - 1] << "\n";
        }
    }

    return 0;
}
