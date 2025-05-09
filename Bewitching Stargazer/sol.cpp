#include <math.h>
#include <iostream>
#include <string>
#include <utility>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <queue>
#include <bits/stdc++.h>
#include <unordered_set>
using namespace std;
long long int bt(long long int st, long long int en, long long int &k) {
    if(en-st+1 < k) {
        return 0;
    }
    if(en == st) {
        return st;
    }
    auto m = (en+st-1)/2;
    if((en-st+1)&1) {
        return m+1 + bt(st, m, k) + bt(m+2, en, k);
    }
    else {
        return bt(st, m, k) + bt(m+1, en, k);
    }
}
int main() {
    int t;
    cin >> t;
    while(t--) {
        long long int n, k;
        cin >> n >> k;
        cout << bt(1, n, k) << endl;
    }
}
// 1 2 3 4 5 6 7 8 9 10 11 12 13 14