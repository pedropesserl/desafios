#include <bits/stdc++.h>
using namespace std;

int main() {
    string line;
    string codigo, str_h, str_m;
    int h, m;
    while (getline(cin, line)) {
        stringstream stream_line(line);
        getline(stream_line, codigo, ' ');
        getline(stream_line, str_h, ' ');
        getline(stream_line, str_m, ' ');
        h = stoi(str_h);
        m = stoi(str_m);

        if (h > 10 || (h == 10 && m > 0)) {
            cout << "Abel deve cancelar " << codigo << "\n";
        } else {
            cout << "Abel deve cursar " << codigo << "\n";
        }
    }
    
    return 0;
}
