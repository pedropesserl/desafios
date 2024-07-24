#include <bits/stdc++.h>
using namespace std;

int n;

vector<vector<int>> t;

void build(vector<int>& src, int ti = 1, int tl = 1, int tr = n) {
    if (tl == tr) {
        if ((size_t)tl < src.size()) {
            t[ti] = vector<int>(1, src[tl]);
        }
        return;
    }
    int tm = (tl + tr) / 2;
    build(src, ti * 2, tl, tm);
    build(src, ti * 2 + 1, tm + 1, tr);
    t[ti] = vector<int>(t[ti * 2].size() + t[ti * 2 + 1].size());
    merge(t[ti * 2].begin(), t[ti * 2].end(),
          t[ti * 2 + 1]. begin(), t[ti * 2 + 1].end(), t[ti].begin());
}

int get_up_bound(int l, int r, int x, int ti = 1, int tl = 1, int tr = n) {
    if (l > r) {
        return 0;
    }
    if (l == tl && tr == r) {
        return upper_bound(t[ti].begin(), t[ti].end(), x) - t[ti].begin();
    }
    int tm = (tl + tr) / 2;
    return get_up_bound(l, min(r, tm), x, ti * 2, tl, tm)
           + get_up_bound(max(l, tm + 1), r, x, ti * 2 + 1, tm + 1, tr);
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

        int lo = -1e9, hi = 1e9;
        int m = 0;
        while (hi >= lo) {
            m = (hi + lo) / 2;
            int pos = get_up_bound(i, j, m);
            if (pos < k) {
                lo = m + 1;
            } else {
                hi = m - 1;
            }
        }
        cout << lo << "\n";
    }

    return 0;
}
