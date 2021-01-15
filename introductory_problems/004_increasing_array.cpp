#include <iostream>
#include <vector>
#include <sstream>
#include <iterator>
#include <climits> 

using namespace std;

template <typename Out>
void split(const string &s, char delim, Out result) {
    istringstream iss(s); 
    string item; 
    while (getline(iss, item, delim)) {
        *result++ = item;
    }
}
vector<string> split(const string &s, char delim) {
    vector<string> elems; 
    split(s, delim, back_inserter(elems)); 
    return elems;
}

// https://cses.fi/problemset/task/1083
void solve(unsigned n, vector<string> &x) {
    unsigned long long c, cprev; 
    cprev = stoul(x[0]); 
    unsigned long long minmoves = 0; 
    for (unsigned i=0; i < n; i++) {
        c = stoul(x[i]); 
        if (c < cprev) {
            minmoves += cprev - c; 
        } else {
            cprev = c; 
        }
    }
    cout << minmoves; 
}

int main() {
    unsigned n;
    string seq; 
    cin >> n; 
    cin.ignore();  // ignore the \n for second input 
    getline(cin, seq);
    vector<string> x = split(seq, ' ');
    solve(n, x); 
}