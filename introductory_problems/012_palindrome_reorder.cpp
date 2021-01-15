#include <iostream>
#include <bits/stdc++.h>

using namespace std;

// https://cses.fi/problemset/task/1755
const char az[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ"; 
const int N = sizeof(az) / sizeof(az[0]);
void solve(string s) {
    int letters[N] = {0}; 
    int n = s.size(); 
    for (const char &c: s) {
        letters[(unsigned)((int)(c) - 65)] += 1; 
    }
    int oddindex = -1; 
    for (unsigned i = 0; i < N; i++) {
        if (letters[i] % 2 == 1) {
            if (oddindex >= 0) {
                cout << "NO SOLUTION";  // cannot form palindrome with multiple odd letter counts 
                return; 
            }
            oddindex = i; 
        }
    }
    if (n % 2 == 0 && oddindex > 0) {
        cout << "NO SOLUTION";  // cannot form palindrome if even number of letters but one odd letter count 
    } else {
        string halfoutput = ""; 
        for (unsigned j = 0; j < N; j++) {
            if (oddindex != (int)j) {
                halfoutput.append(string(letters[j]/2, az[j])); 
            }
        }
        cout << halfoutput ; 
        reverse(halfoutput.begin(), halfoutput.end());
        if (oddindex >= 0) {
            cout << string(letters[oddindex], az[oddindex]); 
        } 
        cout << halfoutput; 
    }
}

int main() {
    string s; 
    getline(cin, s);
    solve(s); 
}