#include <bits/stdc++.h>
using namespace std;
             // 001
#define LIFO 1
             // 010
#define FIFO 2
             // 100
#define PRIORITY 4

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int interacao, idade;
    size_t n;
    cin >> n;
    
    stack<int> lifo;
    queue<int> fifo;
    priority_queue<int> priority;

    int tipo = 7; // 111
    
    for (size_t i = 0; i < n; i++) {
        cin >> interacao >> idade;
        if (interacao == 0) { // entrada
            lifo.push(idade);
            fifo.push(idade);
            priority.push(idade);
        } else { // saida
            if (lifo.top() == idade) {
                lifo.pop();
            } else {
                tipo &= ~LIFO;
            }
            if (fifo.front() == idade) {
                fifo.pop();
            } else {
                tipo &= ~FIFO;
            }
            if (priority.top() == idade) {
                priority.pop();
            } else {
                tipo &= ~PRIORITY;
            }
        }
    }

    switch (tipo) {
        case LIFO:      cout << "lifo\n"; break;
        case FIFO:      cout << "fifo\n"; break;
        case PRIORITY:  cout << "priority\n"; break;
        case LIFO | FIFO:
        case LIFO | PRIORITY:
        case FIFO | PRIORITY:
        case LIFO | FIFO | PRIORITY:
            cout << "ambiguous\n"; break;
        default: cout << "unknown\n";
    }
    return 0;
}
