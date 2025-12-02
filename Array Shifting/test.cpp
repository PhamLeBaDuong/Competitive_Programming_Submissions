#include <math.h>
#include <iostream>
#include <unordered_set>
#include <utility>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <queue>
#include <time.h>
using namespace std;
typedef long long int lli;
lli pow_mod(lli base, lli exp, lli mod) {
    cout << "Calculating " << base << "^" << exp << " mod " << mod << endl;
    lli result = 1;
    base = base % mod;
    while (exp > 0) {
        if (exp % 2 == 1) {
            result = (result * base) % mod;
        }
        exp = exp >> 1;
        base = (base * base) % mod;
    }
    exit(0);
    return result;
}
int main() {
    lli modd = 1e9 + 7;
    
    clock_t tStart = clock();
    unordered_map<lli, lli> mp;
    for(int i = 0; i < 200; i++) {
        mp[pow_mod(2, i, modd)] = i;
    }
    // for(auto &i : mp) {
    //     cout << i.first << ": " << i.second << endl;
    // }
    cout << mp.size() << endl;
    cout <<  (double)(clock() - tStart)/CLOCKS_PER_SEC << endl;
    // cout << mp[5] << endl;
    // cout << mp.size() << endl;
}