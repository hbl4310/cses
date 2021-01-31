#include <iostream>
#include <vector> 

using namespace std; 

// https://cses.fi/problemset/task/1624
const int n = 8;  // size of board 
const int q = 8;  // number of queens 
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

void count(int qs[], bool board[], int &i, int &c) {
    // if (!board[qs[i]]) {
    //     qs[i] += 1; 
    //     count(qs, board, i, c); 
    // } // else ?  or move the check for restricted cells when you hit a valid solution 
    if (i > 0) {
        qs[i] = next_available(qs[i], qs, i - 1); 
    } 
    if (qs[i] < n * n) {
        if (!board[qs[i]]) {
            qs[i] += 1; 
        } else if (i == n - 1) {
            // cout << "[" ;
            // for (int l = 0; l <= i; l++) {
            //     cout << qs[l] << ","; 
            // }
            // cout << "\b]" << endl; 
            qs[i] += 1; 
            c += 1; 
        } else {
            i += 1; 
        }
        count(qs, board, i, c); 
    } else {
        // back trace to previous queen unless already at first 
        if (i == 0) {
            return; 
        } else {
            qs[i] = 0; 
            qs[i - 1] += 1; 
            i -= 1; 
            count(qs, board, i, c); 
        }
    }
}

void solve(bool board[]) {
    int qs[q] = {};
    int c = 0, i = 1; 
    count(qs, board, i, c); 
    cout << c; 
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
    solve(board); 
}