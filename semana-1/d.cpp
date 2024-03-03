#include <bits/stdc++.h>
using namespace std;

#define u64 long unsigned

int main() {
    size_t n;
    cin >> n;
    vector<u64> vetor(n);
    for (size_t i = 0; i < n; i++) {
        cin >> vetor[i];
    }
    u64 movs = 0;
    u64 min = vetor[0];
    for (size_t i = 1; i < n; i++) {
        if (min > vetor[i]) {
            movs += min - vetor[i];
        } else {
            min = vetor[i];
        }
    }
    cout << movs << "\n";

    return 0;
}
