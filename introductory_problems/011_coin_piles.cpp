#include <iostream>
#include <vector>
#include <sstream>
#include <iterator>

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

// https://cses.fi/problemset/task/1754
void solve(int a, int b) {
    // piles have to be of form: a = 2x + y, b = 2y + x; x, y > 0 to be solveable
    // x = 1/3(2a - b); y = 1/3(2b - a)
    int x = 2 * a - b; 
    int y = 2 * b - a; 
    if (x >= 0 && x % 3 == 0 && y >= 0 && y % 3 == 0 ) {
        cout << "YES\n"; 
        // cout << "YES: " << (2 * a - b) / 3 << ", " << (2 * b - a) / 3 << "\n"; 
    } else {
        cout << "NO\n"; 
    }
}

void solve(int t, pair<int, int> piles[]) {
    for (unsigned i = 0; i < (unsigned)t; i++) {
        solve(piles[i].first, piles[i].second); 
    }
}

int main() {
    unsigned t;
    string q; 
    vector<string> x;
    cin >> t; 
    cin.ignore();  // ignore the \n for next input 
    pair<int, int> piles[t]; 
    for (unsigned i=0; i < t; i++) {
        getline(cin, q); 
        x = split(q, ' '); 
        piles[i] = make_pair(stoi(x[0]), stoi(x[1]));
    }
    solve(t, piles); 
}