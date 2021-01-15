#include <iostream>
 
using namespace std;
 
// https://cses.fi/problemset/task/1072
pair<int,int> knight_moves[] = {make_pair(2, 1), make_pair(-2, 1), make_pair(1, 2), make_pair(-1, 2)}; 
 
void solve(int n) {
    int m, x, y, xx, yy; 
    cout << 0 << "\n";  // k = 1 case
    for (int k = 2; k <= n; k ++) {
        m = 0; 
        for (int i = 0; i < k*k; i ++) {
            y = i / k;
            x = i % k;
            // cout << x << "," << y << ": "; 
            for (unsigned j = 0; j < size(knight_moves); j++) {
                yy = y + knight_moves[j].second; 
                xx = x + knight_moves[j].first; 
                m += (yy >= 0) && (yy < k) && (xx >= 0) && (xx < k) && (yy * k + xx > i); 
            }
            // cout << "m=" << m <<"\n"; 
        }
        cout << k*k * (k*k - 1) / 2 << " - " << m << " = " << k*k * (k*k - 1) / 2 - m << "\n";  
        // cout << k*k * (k*k - 1) / 2 - m << "\n"; 
    }
}
 
int main() {
    int n;
    cin >> n; 
    solve(n); 
}