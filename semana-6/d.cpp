#include <bits/stdc++.h>
using namespace std;

void add_bit(vector<long> &bit, long i, long delta) {
    for (; i < (long)bit.size(); i += i & (-i))
        bit[i] += delta;
}

long get_bit(vector<long> &bit, long i) {
    long ans = 0;
    for (; i > 0; i -= i & (-i))
        ans += bit[i];
    return ans;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    long n, n_ops, op, a1, b1, a2, b2, p, d;
    string fita;
    cin >> n;
    cin >> fita;
    vector<long> bit(n); // árvore de Fenwick
    for (long i = 0; i < n; i++) {
        bit[i] = (long)fita[i] - '0';
    }
    for (long i = 0; i < n; i++) {
        long pai = i + (i & (-i));
        if (pai < n) {
            bit[pai] += (long)fita[i] - '0';
        }
    }
    cin >> n_ops;
    for (long i = 0; i < n_ops; i++) {
        cin >> op;
        if (op == 3) {
            cin >> p >> d;
            add_bit(bit, p, d);
            continue;
        }
        cin >> a1 >> b1 >> a2 >> b2 >> d;
        long dr1 = (get_bit(bit, b1) - get_bit(bit, a1 - 1)) % 9;
        long dr2 = (get_bit(bit, b2) - get_bit(bit, a2 - 1)) % 9;
        if (op == 1) {
            cout << ((dr1 + dr2) % 9 == d ? "YES\n" : "NO\n");
        } else {
            cout << ((dr1 * dr2) % 9 == d ? "YES\n" : "NO\n");
        }
    }
    return 0;
}
