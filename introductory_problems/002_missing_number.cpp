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

// https://cses.fi/problemset/task/1083
void solve(long long n, vector<string> &x) {
    // cout << "n = " << n << "\n";
    // cout << "x of length " << x.size() << "\n";
    long long m = (1 + n) * n / 2; 
    for (unsigned i=0; i < x.size(); i++) {
        m -= stoi(x[i]); 
    }
    cout << m; 
}

int main() {
    long long n;
    string seq; 
    cin >> n; 
    cin.ignore();  // ignore the \n for second input 
    getline(cin, seq);
    vector<string> x = split(seq, ' ');
    solve(n, x); 
}