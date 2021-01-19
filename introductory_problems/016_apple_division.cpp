#include <iostream>
#include <vector>
#include <sstream>
#include <iterator>
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

// https://cses.fi/problemset/task/1623
double halfmean(int w[], int n) {
    long long s = 0; 
    for (int i = 0; i < n; i++) {
        s += w[i];
    }
    return (double)s / 2.0; 
}

int fill(int w[], int i, int n, bool x[], long long xsum, double m, long long best) {
    // cout << "i=" << i << ", x={"; 
    // for (int j = 0; j < n; j++) {
    //     cout << x[j] << " "; 
    // }
    // cout << "}, xsum=" << xsum << ", best=" << best << endl;
    if (xsum + w[i] < m + 1) {
        x[i] = 1; 
        xsum += w[i]; 
        if (xsum > m - 1) {
            return xsum; 
        }
    } 
    if (i == n - 1) {
        best = max(best, xsum); 
        if (x[i] == 1) {
            x[i] = 0; 
            xsum -= w[i]; 
        }
        while (x[i] == 0 && i >= 0) {
            i -= 1; 
        }
        if (i < 0) {
            // cout << "exhausted" << endl; 
            return best; 
        }
        x[i] = 0; 
        xsum -= w[i]; 
    }
    return fill(w, i + 1, n, x, xsum, m, best); 
}

void solve(int w[], int n) {
    double m = halfmean(w, n); 
    // cout << "half-mean: " << m << endl; 
    bool x[(unsigned)n] = {}; 
    long long b = fill(w, 0, n, x, 0, m, 0) ; 
    // cout << "best fill = " << b << endl; 
    // cout << "x = {"; 
    // for (int j = 0; j < n; j++) {
    //     cout << x[j] << " "; 
    // }
    // cout << "}" << endl; 
    cout << (unsigned)abs(2 * b - llround(2 * m)); 
}

int main() {
    int n; 
    cin >> n; 
    string wstr; 
    vector<string> wvec; 
    cin.ignore(); 
    getline(cin, wstr); 
    wvec = split(wstr, ' '); 
    int w[n] = {}; 
    for (int i=0; i < n; i++) {
        w[i] = stoi(wvec[i]); 
    }
    solve(w, n); 
}