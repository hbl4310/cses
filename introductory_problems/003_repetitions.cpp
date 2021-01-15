#include <iostream>

using namespace std;

// https://cses.fi/problemset/task/1069
void solve(string seq) {
    int maxcount = 0; 
    int count = 0; 
    char prevchar = '\0'; 
    char currchar = '\0';
    for (string::size_type i=0; i < seq.size(); i++) {
        currchar = seq[i];
        if (currchar != prevchar) {
            count = 1; 
            prevchar = currchar; 
        } else {
            count += 1; 
        }
        if (count > maxcount) {
            maxcount = count; 
        }
    }
    cout << maxcount; 
}

int main() {
    string seq; 
    getline(cin, seq);
    solve(seq); 
}