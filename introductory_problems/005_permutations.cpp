#include <iostream>

using namespace std;

// https://cses.fi/problemset/task/1070
void solve(int n) {
    int seq[n] = {0}; 
    int j = 0, k = -1; 
    bool hassolution = true; 
    for (unsigned i = 0; i < (unsigned)n; i++) {
        j += 2; 
        if (j > n && k <= n) {
            j = 1; 
        }
        if (abs(j - k) == 1) {
            hassolution = false; 
            break; 
        } else {
            seq[i] = j; 
            k = j;
        }
    }
    if (hassolution) {
        for (unsigned i=0; i < (unsigned)n; i++){
            cout << seq[i] << " "; 
        }
    } else {
        cout << "NO SOLUTION"; 
    }
}

int main() {
    int n;
    cin >> n; 
    solve(n); 
}