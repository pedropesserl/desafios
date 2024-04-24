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

int main() {
    /* cin.tie(0)->sync_with_stdio(0); */

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

    size_t it = 0; // real
    size_t it2 = 0; // abstração
    for (long i = 0; i < q; i++) {
        cin >> op;
        if (op == 'm') {
            cin >> d;
            it2 += d;
            it = get_bit(bit, it2 + 1);
        } else if (op == 'd') {
            add_bit(bit, it2 + 1, 1);
            it++;

            n--;

        } else { // op == 'q'
            cout << fita[it] << "\n";

            cout << "(it = " << it << ")\n";
            cout << "(it2 = " << it2 << ")\n";
            cout << "fita: [ ";
            for (long j = 0; j < n; j++) {
                cout << fita[get_bit(bit, j+1)] << " ";
            }
            cout << "]\n";
            cout << "bit:  [ ";
            for (long j = 0; j < n; j++) {
                cout << get_bit(bit, j+1) << " ";
            }
            cout << "]\n";


        }
    }

    return 0;
}
