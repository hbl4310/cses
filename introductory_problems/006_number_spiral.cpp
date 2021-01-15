#include <iostream>
#include <vector>
#include <sstream>
#include <iterator>
#include <climits> 
#include <cmath>

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

// https://cses.fi/problemset/task/1071
long long solve(long long x, long long y) {
    long long d = max(x, y); 
    return 1 + d * (d - 1) + (x - y) * pow(-1, d % 2); 
}

void solve(unsigned t, pair<unsigned, unsigned> coords[]) {
    pair<unsigned, unsigned> coord; 
    for (unsigned i = 0; i < t; i ++) {
        coord = coords[i]; 
        cout << solve(coord.first, coord.second) << "\n"; 
    }
}

int main() {
    unsigned t;
    string q; 
    vector<string> x;
    cin >> t; 
    cin.ignore();  // ignore the \n for next input 
    pair<unsigned, unsigned> coords[t]; 
    for (unsigned i=0; i < t; i++) {
        getline(cin, q); 
        x = split(q, ' '); 
        coords[i] = make_pair(stoi(x[0]), stoi(x[1]));
    }
    solve(t, coords); 
}