#include <iostream>
#include <cmath>
#include <bitset>

using namespace std;

// https://cses.fi/problemset/task/2205
void print(bitset<16> x, unsigned n) {
    for (unsigned i = n; i > 0; i--) {
        cout << x[i-1];
    }
    cout << endl;
}
void solve(unsigned n) {
    int16_t x = 0; 
    int16_t ops[(1 << n) - 1];  // only need ~half this
    int16_t adj; 
    print(x, n);  // zero case 
    for (unsigned i = 0; i < n; i++) {
        adj = 1 << i;  // new unit
        x += adj; 
        ops[adj - 1] = adj;
        print(x, n);
        // reverse adjustments by symmetry 
        for (unsigned j = 1; j < (unsigned)(1 << i); j++) {
            adj = -ops[(1 << i) - 1 - j];
            x += adj; 
            print(x, n); 
            ops[(1 << i) - 1 + j] = adj; 
        }
    }
}

int main() {
    int n;
    cin >> n; 
    solve(n); 
}