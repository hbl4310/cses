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

// https://cses.fi/problemset/task/1623
void merge(int w[], int a, int c, int b) {
    int n = b - a; 
    int w2[(unsigned)n] = {};
    int j = a, k = c; 
    for (int i = 0; i < n; i++) {
        if ((j < c) && (k == b or w[j] <= w[k])) {
            w2[i] = w[j]; 
            j += 1; 
        } else {
            w2[i] = w[k]; 
            k += 1; 
        }
    }
    for (int i = 0; i < n; i++) {
        w[a + i] = w2[i]; 
    }
}

void sort(int w[], int a, int b) {
    int n = b - a; 
    int c = 0; 
    if (n > 1) {
        c = a + n / 2; 
        sort(w, a, c);
        sort(w, c, b); 
        merge(w, a, c, b);
    } 
}

void solve(int w[], int n) {
    int a[n] = {}, b[n] = {}; 
    int ai = 0, bi = 0, aw = 0, bw = 0; 
    sort(w, 0, n); 
    cout << "sorted w: "; 
    for (int i = 0; i < n; i++) {
        cout << w[i] << " "; 
    }
    for (int i = n - 1; i >= 0; i--) {
        if (aw < bw) {
            a[ai] = w[i]; 
            ai += 1; 
            aw += w[i]; 
        } else {
            b[bi] = w[i]; 
            bi += 1; 
            bw += w[i]; 
        }
    }
    cout << endl << "a: "; 
    for (int i = 0; i < ai; i++) {
        cout << a[i] << " "; 
    }
    cout << endl << "b: "; 
    for (int i = 0; i < bi; i++) {
        cout << b[i] << " "; 
    }
    cout << endl; 
    cout << abs(aw - bw); 
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