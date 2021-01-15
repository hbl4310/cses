#include <iostream>
#include <climits>

using namespace std;

// https://cses.fi/problemset/task/1617
int m = 1000000007; 
int k = (UINT_MAX % m) + 1; 
void solve(int n) {
    unsigned d = n / 32; 
    unsigned r = n % 32; 
    long long x = 1;  // need to fit up to m^2
    // cout << "divmod(" << n << ", 32) = " << d << ", " << r << "\n";
    for (unsigned i = 0; i < d; i++) {
        x = (x * (long long)k) % m; 
    }
    for (unsigned j = 0; j < r; j++) {
        x = (2 * x) % m; 
    }
    cout << x; 
}

int main() {
    int n;
    cin >> n; 
    solve(n); 
}