#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    
    size_t total = 0;
    for (int i = 0; i < n; i++) {
        size_t a;
        cin >> a;
        if (a > 10) {
            total += a - 10;
        }
    }

    cout << total << "\n";

    return 0;
}
