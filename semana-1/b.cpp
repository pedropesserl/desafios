#include <bits/stdc++.h>
using namespace std;

int main() {
    string s;
    cin >> s;
    vector<int> freqs(26, 0);
    for (char c : s) {
        freqs[c - 'A']++;
    }
    int idx_frequencia_impar = -1;
    for (int i = 0; i < 26; i++) {
        if (freqs[i] % 2 != 0) {
            if (idx_frequencia_impar != -1) {
                cout << "NO SOLUTION\n";
                return 0;
            }
            idx_frequencia_impar = i;
        }
    }
    if (s.size() % 2 == 0) {
        if (idx_frequencia_impar != -1) {
            cout << "NO SOLUTION\n";
            return 0;
        }
        for (int i = 0; i < 26; i++) {
            for (int j = 0; j < freqs[i] / 2; j++) {
                cout << (char)(i + 'A');
            }
        }
        for (int i = 25; i >= 0; i--) {
            for (int j = 0; j < freqs[i] / 2; j++) {
                cout << (char)(i + 'A');
            }
        }
        cout << "\n";
    } else {
        /* numero impar de letras, apenas uma frequencia impar */
        for (int i = 0; i < idx_frequencia_impar; i++) {
            for (int j = 0; j < freqs[i] / 2; j++) {
                cout << (char)(i + 'A');
            }
        }
        for (int i = idx_frequencia_impar + 1; i < 26; i++) {
            for (int j = 0; j < freqs[i] / 2; j++) {
                cout << (char)(i + 'A');
            }
        }
        for (int j = 0; j < freqs[idx_frequencia_impar]; j++) {
            cout << (char)(idx_frequencia_impar + 'A');
        }
        for (int i = 25; i > idx_frequencia_impar; i--) {
            for (int j = 0; j < freqs[i] / 2; j++) {
                cout << (char)(i + 'A');
            }
        }
        for (int i = idx_frequencia_impar - 1; i >= 0; i--) {
            for (int j = 0; j < freqs[i] / 2; j++) {
                cout << (char)(i + 'A');
            }
        }
        cout << "\n";
    }

    return 0;
}
