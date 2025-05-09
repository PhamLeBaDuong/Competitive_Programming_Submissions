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
        cin >> n;
        vector<int> a(n);
        bool flag = false;
        for(int i = 0; i < n; i++) {
            cin >> a[i];
            if(!flag && i > 0 && 2*min(a[i-1],a[i]) > max(a[i-1],a[i])) {
                flag = true;
            }
        }
        if(flag) {
            cout << "YES" << endl;
        }
        else {
            cout << "NO" << endl;
        }
    }
}