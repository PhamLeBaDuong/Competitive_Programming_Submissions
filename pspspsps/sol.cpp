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
    int t;
    cin >> t;
    while(t--) {
        int n;
        string s;
        cin >> n >> s;
        vector<bool> pre(n,true);
        pre[0] = false;
        vector<bool> suf(n,true);
        for(int i = n-1; i >= 0; i--) {
            if(s[i] != 's') {
                suf[i] = false;
            }
            else {
                break;
            }
        }
        for(int i = 1; i < n; i++) {
            if(s[i] != 's') {
                pre[i] = false;
            }
            else {
                break;
            }
        }
        bool flag = false;
        for(int i = 0; i < n-1; i++) {
            if(s[i] == 'p' && (pre[i] || suf[i])) {
                flag = true;
                cout << "NO" << endl;
                break;
            }
        }
        if(!flag) {
            cout << "YES" << endl;
        }
    }
}
// s . . p . .
// 4 3 1 2