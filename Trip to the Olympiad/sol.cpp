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
int main() {
    cout << (1 ^6 ) + (6 ^7) + (7^1 ) << endl;
    cout << (8^7) + (7^1) + (1^8) << endl;
    return 0;
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while(t--) {
        int l, r;
        cin >> l >> r;
        if(l == 0 && r == 2) {
            cout << 1 << " " << 2 << " " << 0 << endl;
            continue;
        }
        int curr = 1;
        while(curr < r) {
            curr*=2;
        }
        curr--;
        int temp = 1;
        while(curr > l) {
            curr -= temp;
            // curr = max(curr-temp, 0);
            temp *= 2;
        }
        int i = 1;
        int a = curr + i;
        int b = curr + temp*2 + ~(temp^i);
        // cout << a << " " << b << endl;
        i++;
        while(min(a, b+(b&1?-1:0)) < l || max(a, b+(b&1?0:1)) > r) {
            a = curr + i;
            b = curr + temp*2 + ~(temp^i);
            i++;
        }
        cout << a << " " << b << " " << b + (b & 1 ? -1 : 1) << endl;
    }
}