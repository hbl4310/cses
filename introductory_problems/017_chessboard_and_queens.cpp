#include <iostream>
#include <vector> 

using namespace std; 

// https://cses.fi/problemset/task/1624
const int n = 4; 
// starting from position a on board, find next square which isnt being attacked by queen on x
int next_available(int a, int x) {
    a = max(a, (x/n + 1) * n);
    if ((x%n - a%n == a/n - x/n) || (x%n == a%n) || (a%n - x%n == a/n - x/n)) {
        a += 1; 
    }
    return a; 
}
int next_available(int a, int qs[], int i) {
    int b = a; 
    while (b < n * n) {
        for (int j = i; j >= 0; j--) {
            b = next_available(b, qs[j]); 
        }
        if (a == b) {
            break;
        } 
        a = b; 
    }
    return b; 
}

int count(int qs[], int i, bool board[], int c = 0) {
    cout << "i=" << i << " q[i] = {" ;
    for (int j = 0; j < i; j++){
        cout << qs[j] << " "; 
    }
    cout << "}  c=" << c << endl; 
    if (!board[qs[i]]) {
        qs[i] += 1; 
        c = count(qs, i, board, c); 
    }
    if (i > 0) {
        qs[i] = next_available(qs[i], qs, i - 1); 
        cout << "  placing next q at " << qs[i] << endl; 
    } 
    if (qs[i] < n * n) {
        if (i == n - 1) {
            cout << "  counting qs[" << i << "] = " << qs[i] << endl; 
            qs[i] += 1; 
            c = count(qs, i, board, c + 1); 
        } else {
            c = count(qs, i + 1, board, c); 
        }
    } else {
        // back trace to previous queen unless already at first 
        if (i > 0) {
            cout << "  backtracking with qs[" << i << "] = " << qs[i] << endl;
            qs[i] = 0; 
            qs[i - 1] += 1; 
            c = count(qs, i - 1, board, c); 
        }
    }
    return c; 
}

void solve(int q, bool board[]) {
    // int board[n*n] = {}; 
    int qs[q] = {};
    int c = 0; 

    cout << count(qs, 1, board, c); 

    // for (int i = 0; i < n; i++) {
    //     a = i; 
    //     for (int j = 0; j < q; j++) {
    //         if (board[a]) {
    //             qs[j] = a; 
    //         }
    //         for (int k = j; k > 0; k--) {
    //             a = next_available(a, qs[k]); 
    //             cout << "new a=" << a << endl;
    //         }
    //         if (a >= n*n) {
    //             break; 
    //         }
    //     }
    //     if (a < n) {
    //         c += 1; 
    //     }
    //     // place first queen on lowest available square given reserveds
    //     // place next queens given previous ones 
    //     for (int j = 0; j < n; j++) {
    //         cout << qs[j] << " "; 
    //         qs[j] = 0;
    //     }
    //     cout << endl; 
    //     break; 
    // }
}

void read_board(bool board[]) {
    string row; 
    for (int i = 0; i < n; i++) {
        getline(cin, row); 
        for (int j = 0; j < n; j++) {
            board[n * i + j] = row[j] == '.'; 
        }
    }
}

int main() {
    bool board[n*n];
    read_board(board); 
    // cout << next_available(0, 0) << endl; 
    // cout << next_available(0, 1) << endl; 
    // cout << next_available(0, 2) << endl; 
    // cout << next_available(0, 6) << endl; 
    // cout << next_available(0, 7) << endl; 
    // cout << next_available(16, 0) << endl; 
    // cout << next_available(18, 0) << endl; 
    // cout << next_available(16, 2) << endl; 
    // cout << next_available(57, 56) << endl; 
    // cout << next_available(63, 0) << endl; 
    // cout << next_available(63, 7) << endl; 
    // cout << next_available(0, 5) << endl; 
    // cout << next_available(7, 5) << endl; 
    // int qs[] = {0, 5}; 
    // cout << next_available(0, qs, 1) << endl; 
    solve(4, board); 
}