#include <iostream>

using namespace std;

// https://cses.fi/problemset/task/1092
void printseq(int x, int m, bool b) {
    cout << m << "\n"; 
    int c = x; 
    for (int i = 1; i <= m; i++) {
        c += (i % 2 == b) * 2 + 1; 
        cout << c << " "; 
    }
}

void solve(long long n) {
    long long totalsum = (1 + n) * n / 2;
    if (totalsum % 2 == 1) {
        cout << "NO" ; 
    } else {
        cout << "YES\n" ; 
        if (n % 2 == 0) {
            printseq(0, n/2, 0); 
            cout << "\n"; 
            printseq(-1, n/2, 1); 
            cout << "\n"; 
        } else {
            printseq(-2, (n+1)/2, 1); 
            cout << "\n"; 
            printseq(0, n/2, 1); 
        }
    }
}

int main() {
    int n;
    cin >> n; 
    solve(n); 
}