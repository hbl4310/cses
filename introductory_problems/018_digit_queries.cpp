#include <iostream> 
#include <vector>
#include <cmath> 
#include <string>

using namespace std; 

// https://cses.fi/problemset/task/1622
vector<long long unsigned> generate_cache(unsigned n) {
    // index i of cache stores cumulative number of digits up to 10^(i+1) - 1
    // number of digits from [1, 10^n) = (n+1)*(10^(n+1) - 10^n)
    vector<long long unsigned> cache; 
    long long unsigned x = 0; 
    for (unsigned i = 0; i < n; i++) {
        x += (long long unsigned)(i + 1) * ((long long unsigned)(round(pow(10, i + 1))) - (long long unsigned)(round(pow(10, i)))); 
        cache.push_back(x);
    }
    return cache;
}

const int m = 16;
const vector<long long unsigned> cache = generate_cache(m);

char solve(long long unsigned k) {
    int n = 0; 
    long long unsigned x = 0; 
    for (unsigned i = 0; i < m; i++) {
        if (k <= cache[i]) {
            break; 
        } else {
            x = cache[i];
            n = i + 1; 
        }
    }
    // x: number of digits in bracket 
    // n: 10^n is the start of the bracket
    // n + 1: digits per number in bracket 
    // (k - x - 1) / (n + 1): number above 10^n the digit is in 
    // (k - x - 1) % (n + 1): digit index within number 
    string y = to_string((long long unsigned)(round(pow(10, n)) + (k - x - 1) / (n + 1))); 
    // cout << n << ": " << x << endl; 
    // cout << (k - x - 1) / (n + 1) << " " << (k - x - 1) % (n + 1) << endl; 
    // cout << "y=" << y << endl; 
    return y[(k - x - 1) % (long long unsigned)(n + 1)]; 
}
void solve(unsigned q, long long unsigned k[]) {
    for (unsigned i = 0; i < q; i++) {
        cout << solve(k[i]) << endl;
    }
}

int main() {
    unsigned q; 
    cin >> q; 
    // cout << solve(q); 
    long long unsigned k[q]; 
    for (unsigned i = 0; i < q; i++) {
        cin.ignore(); 
        cin >> k[i]; 
    }
    solve(q, k); 
}