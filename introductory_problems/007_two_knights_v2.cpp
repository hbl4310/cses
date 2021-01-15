#include <iostream>

using namespace std;

// https://cses.fi/problemset/task/1072
// only need the moves which are "in front" of the current position
pair<int,int> knight_moves[] = {make_pair(2, 1), make_pair(-2, 1), make_pair(1, 2), make_pair(-1, 2)}; 
int num_attacking_places(unsigned k) {
    // base case: cannot fit two pieces on board
    if (k <= 2) {
        return 0; 
    }
    return (k - 1) * (k - 2) * (2 + 2);  // count number of 3x2 arrangements on grid 
}

long long num_safe_places(long long k) {
    long long total_places = k*k * (k*k - 1) / 2; 
    return total_places - (long long)num_attacking_places(k); 
}

void solve(int n) {
    for (int k = 1; k <= n; k ++) {
        cout << num_safe_places(k) << "\n"; 
    }
}

int main() {
    int n;
    cin >> n; 
    solve(n); 
}