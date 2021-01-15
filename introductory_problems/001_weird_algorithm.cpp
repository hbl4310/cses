#include <iostream>

using namespace std;

// https://cses.fi/problemset/task/1068
// INT_MAX = 2147483647
// UINT_MAX = 4294967295 
// LONG_MAX = 2147483647
// ULONG_MAX = 4294967295 
// LLONG_MAX = 9,223,372,036,854,775,807
// ULLONG_MAX = 18,446,744,073,709,551,615 
void solve(unsigned x) {
    cout << x << " ";
    if (x > 1) {
        if (x % 2 == 0) {
            solve(x / 2); 
        } else {
            solve(3*x + 1);
        }
    }
}

int main() {
    unsigned x;
    cin >> x;
    solve(x); 
}