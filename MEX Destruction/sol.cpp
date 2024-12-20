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
    // vector<int> res;
    while(t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for(int i = 0; i < n; i++) {
            cin >> a[i];
        }
        int i = 0;
        int j = n-1;
        while(a[i] == 0 && i < n) {
            i++;
        }
        if(i == n) {
            cout << 0 << endl;
            // res.push_back(0);
            continue;
        }
        while(a[j] == 0 && j >= 0) {
            j--;
        }
        bool flag = false;
        for(int ii = i; ii <= j; ii++)
        {
            if(a[ii] == 0) {
                cout << 2 << endl;
                // res.push_back(2);
                flag = true;
                break;
            }
        }
        if(!flag) {
            cout << 1 << endl;
            // res.push_back(1);
        }

    }
    // cout << endl;
    // for(auto i : res) {
    //     cout << i << " ";
    // }
    // cout << endl;
}