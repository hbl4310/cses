#include <iostream>
#include <vector> 
#include <cmath>
// #include <chrono> 

using namespace std;
// using namespace chrono; 

// https://cses.fi/problemset/task/1622
unsigned count_letters(string s, int letters[]) {
    unsigned nunique = 0; 
    unsigned l = 0; 
    for (const char &c: s) {
        l = (unsigned)((int)(c) - 97); 
        if (letters[l] == 0) {
            nunique += 1; 
        }
        letters[l] += 1; 
    }
    return nunique; 
}

const int N = 26; 
const char az[N + 1] = "abcdefghijklmnopqrstuvwxyz";
int factorial(int x) {
    if (x <= 1) {
        return 1; 
    }
    return x * factorial(x - 1);  // x <= 8
}

void rebase(unsigned i, unsigned base, unsigned buffer[], unsigned n) {
    buffer[n - 1] = i; 
    for (unsigned l = n - 1; l > 0; l--) {
        buffer[l - 1] = buffer[l] / base; 
        buffer[l] = buffer[l] % base; 
        if (buffer[l - 1] == 0) {
            break; 
        }            
    }
}

void increment(unsigned x[], unsigned incr, unsigned base, unsigned n) {
    unsigned a, b = 0; 
    for (unsigned i = n - 1; i >= 0; i--) {
        a = (x[i] + incr) % base; 
        b = (x[i] + incr) / base; 
        x[i] = a; 
        if (b == 0) {
            break; 
        }
        incr = b; 
    }
}

bool check_counts(unsigned x[], unsigned counts[], unsigned n, unsigned nunique) {
    unsigned checks[nunique] = {}; 
    for (unsigned i = 0; i < n; i++) {
        checks[x[i]] += 1; 
        if (checks[x[i]] > counts[x[i]]) {
            return false; 
        }
    }
    return true; 
}

void print(unsigned x[], char letters[], unsigned n) {
    for (unsigned i = 0; i < n; i++) {
        cout << letters[x[i]]; 
    }
    cout << endl;
}

struct Perm {
    unsigned n; 
    unsigned total; 
}; 
Perm count_permutations(int letters[N], unsigned nunique, char unique_letters[], unsigned unique_letters_count[]) {
    int n = 0, l = 0, k = 1; 
    unsigned j = 0; 
    for (unsigned i = 0; i < N; i++) {
        l = letters[i]; 
        if (l > 0) {
            n += l; 
            k *= factorial(l); 
            unique_letters[j] = az[i]; 
            unique_letters_count[j] = l;
            j += 1; 
        }
    }
    Perm result = {(unsigned)n, (unsigned)(factorial(n) / k)}; 
    return result; 
}

int iinit(unsigned counts[], unsigned base) {
    int x = 0; 
    for (unsigned i = 1; i < base; i++) {
        x += i * (int)(round(pow(base, (base - i - 1)))); 
    }
    return x; 
}

void solve(string s) {
    // number of each letter and total unique letters
    int letters[N] = {}; 
    unsigned nunique = count_letters(s, letters); 
    // unique letter frequencies, and calculate permutations 
    char unique_letters[nunique] = {}; 
    unsigned unique_letters_count[nunique] = {}; 
    Perm perms = count_permutations(letters, nunique, unique_letters, unique_letters_count); 
    cout << perms.total << endl;
    // count through all possible permutations of unique letters and ignore illegal ones
    unsigned buffer[perms.n] = {}; 
    unsigned i = iinit(unique_letters_count, nunique), j = 0; 
    rebase(i, nunique, buffer, perms.n);
    while (j < perms.total) {
        // rebase(i, nunique, buffer, perms.n);
        if (check_counts(buffer, unique_letters_count, perms.n, nunique)) {
            print(buffer, unique_letters, perms.n); 
            j += 1; 
        } 
        increment(buffer, 1, nunique, perms.n); 
    } 
}

int main() {
    string s; 
    getline(cin, s);
    // auto start = high_resolution_clock::now(); 
    solve(s); 
    // auto stop = high_resolution_clock::now(); 
    // auto duration = duration_cast<microseconds>(stop - start); 
    // cout << duration.count() << endl; 
}