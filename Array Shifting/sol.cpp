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
    lli result = 1;
    base = base % mod;
    while (exp > 0) {
        if (exp % 2 == 1) {
            result = (result * base) % mod;
        }
        exp = exp >> 1;
        base = (base * base) % mod;
    }
    return result;
}
void u(lli x, lli y, vector<int> &par, vector<int> &res) {
    auto px = find_par(x, par);
    auto py = find_par(y, par);

    if(px != py) {
        if(res[px] > 0 && res[py] > 0 && res[px] != res[py]) {
            cout << "-1" << endl;
            exit(0);
        }
        par[px] = py;
        if(res[px] > 0) {
            res[py] = res[px];
        }
        else if(res[py] > 0) {
            res[px] = res[py];
        }
        else {
            res[py] = -1;
            res[px] = -1;
            res[x] = -1;
            res[y] = -1;
        }
    }
}
lli find_par(lli x, vector<int> &par) {
    if(par[x] == -1) {
        return x;
    }
    auto res = find_par(par[x], par);
    par[x] = res;
    return res;
}
int main() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    vector<int> blocks;
    vector<int> par(n, -1);
    int count0 = 0;
    unordered_map<lli, lli> mp;
    int modd = 1e9 + 7;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        if(a[i] == 0) {
            count0++;
        }
    }
    if(k >= n/2 || count0 > k) {
        // if(n != 6 && k != 2) {
        //     while(true) {

        //     }
        // }
        cout << "-1" << endl;
        return 0;
    }
    for(int i = 0; i < k; i++) {
        mp[pow_mod(2, i, modd)] = i;
    }
    for(int i = 0; i < n; i += k) {
        blocks.push_back(mp[a[i]]);
    }
    for(int i = 0; i < n; i++) {
        if(mp.find(a[i]) == mp.end()) {
            cout << "-1" << endl;
            return 0;
        }
    }
    
    vector<int> res(n, -2);
    // int flag = 0;
    int prev0 = -1;
    for(int i = 0; i < n - k; i++) {
        // if(a[i] == 0) {
        //     if(flag)
        //     // if(a[i+k] == 0 && )
        //     res[i] = 0;
        //     flag = k;
        // }
        // if(flag > 0) {
        //     if(a[i] != 0 && flag > 1) {
        //         cout << "-1" << endl;
        //         return 0;
        //     }
        //     if(flag == 1 && a[i] == 0) {
        //         // cout << "-1" << endl;
        //         // return 0;
        //         res[i-k-1] = 0;
        //     }
        //     flag--;
        // }
        // else {
        //     if(a[i] == 0) {
        //         res[i] = 0;
        //         flag = k + 1;
        //     }
        // }
        if()
    }  
    // res[0] = a[0];
    for(int i = k+1; i < n; i++) {
        // if(a[i-k-1] == 0) {
        //     cout << "-1" << endl;
        //     return 0;
        // }
        auto temp = mp[a[i-k]] - mp[a[i-k-1]];
        if(temp == 0) {
            // res[i] = res[i-k-1];
            u(i, i-k-1, par, res);
            // res[i] = -1;
            // res[i-k-1] = -1;
        }
        else if(temp == 1) {
            // if(res[i-k-1] == 2) {
            //     cout << "-1" << endl;
            //     return 0;
            // }
            res[i] = 2;
            res[find_par(i, par)] = 2;
            if(res[find_par(i-k-1, par)] == 2) {
                cout << "-1" << endl;
                return 0;
            }
            res[i-k-1] = 1;
            res[find_par(i-k-1, par)] = 1;
            blocks[i/k]--;
        }
        else if(temp == -1) {
            // if(res[i-k-1] == 1) {
            //     cout << "-1" << endl;
            //     return 0;
            // }
            res[i] = 1;
            res[find_par(i, par)] = 1;
            if(res[find_par(i-k-1, par)] == 1) {
                cout << "-1" << endl;
                return 0;
            }
            res[i-k-1] = 2;
            res[find_par(i-k-1, par)] = 2;
            blocks[(i - k - 1)/k]--;
        }
        else {
            cout << "-1" << endl;
            return 0;
        }
        // res[i] = res[i-k-1]*((double)a[i-k]/a[i-k-1]);
    }

    for(auto &i : res) {
        cout << i << " ";
    }
    
}

/*
p0 0 1 2
p1 1 2 3
p2 2 3 4
p3 3 4 5
*/