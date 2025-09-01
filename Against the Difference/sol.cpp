#include <math.h>
#include <iostream>
#include <string>
#include <utility>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <queue>
#include <unordered_set>
using namespace std;
int main() {
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        vector<int> dpCount(n+1,0);
        vector<int> prev(n+1,-1);
        vector<int> prevv(n+1,-1);
        vector<int> next(n+1,-1);
        vector<int> dp(n);
        for(int i = 0; i < n; i++) {
            cin >> a[i];
        }
        if(a[0] == 1) {
            dp[0] = 1;
        }
        else {
            dpCount[a[0]] = 1;
            prevv[a[0]] = 0;
            prev[a[0]] = 0;
        }
        for(int i = 1; i < n; i++) {
            if(a[i] == 1) {
                dp[i] = dp[i-1] + 1;
            }
            else {
                if(prev[a[i]] == -1) {
                    prev[a[i]] = i;
                    prevv[a[i]] = i;
                }
                else {
                    next[prev[a[i]]] = i;
                    prev[a[i]] = i;
                }
                dpCount[a[i]]++;
                if(dpCount[a[i]] >= a[i]) {
                    dp[i] = max(dp[i-1], (prevv[a[i]] == 0 ? 0 : dp[prevv[a[i]]-1]) + a[i]);
                    prevv[a[i]] = next[prevv[a[i]]];
                    
                }
                else {
                    dp[i] = dp[i-1];
                }
            }
        }
        cout << dp[n-1] << endl;
    }
}