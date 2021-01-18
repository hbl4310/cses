#include <iostream>

using namespace std;

// https://cses.fi/problemset/task/1622
const char az[] = "abcdefghijklmnopqrstuvwxyz";
void solve(string s) {
    int n = s.length(); 
    int letters[sizeof(az)/sizeof(az[0])] = {0}; 
    for (const char &c: s) {
        letters[(unsigned)((int)(c) - 65)] += 1; 
    }
    cout << n << "\n";

}

int main() {
    string s; 
    getline(cin, s);
    solve(s); 
}