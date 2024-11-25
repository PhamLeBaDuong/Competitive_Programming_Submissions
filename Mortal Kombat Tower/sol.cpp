#include <utility>
#include <queue>
#include <unordered_set>
#include <iostream>
#include <math.h>
using namespace std;

long long bt(int i, vector<long long> &arr, vector<int> &dp) {
    // cout << i << " " << turn << endl;
    if(i >= arr.size()) {
        return 0;
    }
    if(dp[i] != -1) {
        return dp[i];
    }
    // long long res = 0;
    dp[i] = 0;
    // if(turn == 0) {
        long long beatOne = arr[i];
        long long beatTwo = arr[i];
        if(i+1 < arr.size()) {
            beatTwo += arr[i+1];
        }
        dp[i] += min(beatOne + min(bt(i+2, arr, dp), bt(i+3,arr,dp)), beatTwo + min(bt(i+4,arr,dp), bt(i+3,arr,dp)));
    // }
    // else {
    //     res += min(bt(i+1,arr,0), bt(i+2,arr,0));
    // }
    // cout << res << endl;
    return dp[i];
}

int main() {
    // cout << INT_MIN << endl;
    long long n;
    cin >> n;
    vector<long long> res;
    for(int ii = 0; ii < n; ii++) {
        long long t;
        cin >> t;
        vector<long long> arr(t);
        vector<int> dp(t, -1);
        for(int i = 0; i < t; i++) {
            long long j;
            cin >> j;
            arr[i] = j;
        }
        // cout << bt(0,arr,0) << endl;
        res.push_back(bt(0,arr,dp));
        // cout << endl;
    }
    for(auto i : res) {
        cout << i << endl;
    }
}