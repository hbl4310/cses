#include <iostream>
#include <cmath>

using namespace std;

// https://cses.fi/problemset/task/1618
void solve(int n) {
    unsigned x = 0; 
    // 13 is upper limit sinze 5^12 < 10^9 < 5^13
    for (unsigned i = 1; i < 13; i++) {
        int p = round(pow(5, i)); 
        // cout << p << " "; 
        if (n >= p) {
            x += static_cast<unsigned>(n / p); 
            cout << x << " "; 
        } else {
            break; 
        }
    }
    cout << "\n" << x; 
}

int main() {
    int n;
    cin >> n; 
    solve(n); 
}

// 374960399
// 129872833
//  93740092