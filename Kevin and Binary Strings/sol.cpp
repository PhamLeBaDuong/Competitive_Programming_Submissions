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
#define MAX_LEN 50000
int main() {

    // ios_base::sync_with_stdio(false);
    // cin.tie(NULL);
    // char buff[10000];
    // cin.rdbuf()->pubsetbuf(buff, sizeof(buff));

    int t;
    cin >> t;
    // cin.ignore();
    // string s;
    // s.reserve(5000);
    while(t--) {
        char s[MAX_LEN+1];
        // cin.read(s,50000);
        // // getline(cin,s,MAX_LEN);
        // cin >> s;
        scanf("%s",s);
        // getline(cin,s);
        int n = strlen(s);
        cout << strlen(s) << endl;
        int l2 = 1;
        int r2 = n;
        int find0 = 0;
        while(find0 < n && s[find0] != '0') {
            find0++;
        }
        int target = find0 == n ? 1 : n-find0;
        int l1 = 1;
        int r1 = l1+target-1;
        int maxx = INT_MIN;
        for(int i = 0; i < n-target; i++) {
            if(s[i] == '0') {
                continue;
            }
            int temp = n-target;
            int j = i;
            int count = 0;
            while(temp < n) {
                if(s[j] != s[temp])
                {
                    count++;
                }
                j++;
                temp++;
            }
            if(count > maxx) {
                maxx = count;
                l1 = i+1;
                r1 = l1+target-1;
            }
        }
        cout << l1 << " " << r1 << " " << l2 << " " << r2 << endl;
    }
}