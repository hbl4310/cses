#include <iostream>
#include <map> 
#include <cmath>

using namespace std;

// https://cses.fi/problemset/task/1618
unsigned factorise(unsigned x, unsigned k, map<unsigned,unsigned> &cache) {
    if (x % k == 0) { 
        if (cache.find(x) != cache.end()) {
            return cache[x]; 
        }
        unsigned numfactors = factorise(x / k, k, cache) + 1; 
        if (numfactors > 1 ) {
            cache[x] = numfactors; 
        }
        return numfactors;
    }
    return 0; 
}
void solve(unsigned n) {
    // count number of 5 factors 
    unsigned x = 0; 
    std::map<unsigned,unsigned> cache;
    // map is size constrained to map::max_size = SIZE_T_MAX = 2^64-1  which is the number of available hashkeys I think
    // this solution runs into issues resulting from cache becoming too large and slow
    for (unsigned i = 1; i <= n; i++) {
        if (i % 5 == 0) {
            x += factorise(i, 5, cache); 
        }
    }
    cout << x << "\n"; 
    // for (auto& elem: cache) {
    //     cout << elem.first << ": " << elem.second << "\n"; 
    // }
}

int main() {
    unsigned n;
    cin >> n; 
    solve(n); 
}

// 374960399
// 129872833
// 93740092
