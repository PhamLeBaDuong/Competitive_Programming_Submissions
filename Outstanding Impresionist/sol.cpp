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
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;   
        vector<vector<int>> a(n,vector<int>(2));
        vector<int> mp(2*n+1, 0);
        int count = 0;
        for(int i = 0; i < n; i++) {
            cin >> a[i][0] >> a[i][1];
            if(a[i][0] == a[i][1]) {
                count += (mp[a[i][0]] == 0 ? 1 : 0);
                mp[a[i][0]]++;
            }
        }
        bool flag = false;
        bool overlapped = false;
        for(int i = 0; i < n; i++) {
            flag = true;
            overlapped = a[i][0] == a[i][1];
            if(a[i][1]-a[i][0]+1 <= count) {
                flag = false;
                for(int j = a[i][0]; j <= a[i][1]; j++) {
                    if(mp[j]-overlapped == 0) {
                        flag = true;
                        break;
                    }
                }
            }
            cout << (flag ? 1 : 0);
        }
        cout << "\n";
    }
}