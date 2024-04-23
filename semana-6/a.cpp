#include <bits/stdc++.h>
using namespace std;

void merge_sort(vector<long> &a, long l, long r, long *swaps) {
    if (r - l <= 1) {
        return;
    }
    long mi = l + (r - l) / 2;
    merge_sort(a, l, mi, swaps);
    merge_sort(a, mi, r, swaps);
    vector<long> aux (r - l);
    long i = l, j = mi;
    for (long k = 0; k < r - l; k++) {
        if (i < mi && j < r) {
            if (!(a[i] < a[j])) {
                *swaps += mi - i;
            }
            if (a[i] < a[j]) {
                aux[k] = a[i++];
            } else {
                aux[k] = a[j++];
            }
        } else if (i < mi) {
            aux[k] = a[i++];
        } else {
            aux[k] = a[j++];
        }
    }
    copy(aux.begin(), aux.end(), a.begin()+l);
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    long n, h;
    cin >> n >> h;
    vector<long> participantes(n);
    for (long i = 0; i < n; i++) { cin >> participantes[i]; }
    vector<long> na_hora(h);
    copy(participantes.begin(), participantes.begin() + h, na_hora.begin());
    long na_hora_swaps = 0;
    merge_sort(na_hora, 0, h, &na_hora_swaps);
    long swaps = 0;
    merge_sort(participantes, 0, n, &swaps);
    cout << swaps - na_hora_swaps << "\n";

    return 0;
}
