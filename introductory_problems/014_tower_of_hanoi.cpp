#include <iostream>

using namespace std;

// https://cses.fi/problemset/task/2165
const int numstacks = 3; 
// 1: rebase n-1 tower onto a free stack
// 2: move n onto other free stack 
// 3: rebase n-1 tower onto n
// total moves = m_n = 2*m_(n-1) + 1
void rebase(int n, int a, int b, int c) {
    // rebase stack of base n from a to b, where c is free stack
    if (n >= 1) {
        rebase(n - 1, a, c, b); 
        cout << a << " " << b << endl; 
        rebase(n - 1, c, b, a); 
    }
}

void solve(unsigned n) {
    unsigned m = 0; 
    for (unsigned i = 0; i < n; i++) {
        m = 2 * m + 1; 
    }
    cout << m << "\n"; 
    rebase(n, 1, 3, 2); 
}

int main() {
    unsigned n;
    cin >> n; 
    solve(n); 
}