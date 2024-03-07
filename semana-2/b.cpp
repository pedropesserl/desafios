#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0)->sync_with_stdio(0);

    stack<int> torres;
    size_t n;
    cin >> n;
    int altura;
    char sentido;

    for (size_t i = 0; i < n; i++) {
        cin >> altura >> sentido;
        if (sentido == 'L') {
            if (!torres.empty() && torres.top() <= altura) {
                cout << "N\n";
                return 0;
            }
            torres.push(altura);
        } else { // sentido == 'O'
            if (torres.empty() || torres.top() != altura) {
                cout << "N\n";
                return 0;
            }
            torres.pop();
        }
    }

    cout << (torres.empty() ? "S\n" : "N\n");

    return 0;
}
