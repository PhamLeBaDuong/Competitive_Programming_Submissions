#include <math.h>
#include <iostream>
#include <string>
#include <utility>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <queue>
#include <unordered_set>
#include <climits>
using namespace std;
typedef pair<pair<int, int>, int> pipii;
typedef pair<int, int> pii;
typedef long long int lli;

int bt(int curr, vector<int> &a, int d, int currSum, int prevSum, vector<vector<vector<int>>> &dp, vector<int> &pre) {
    if(curr >= a.size()) {
        return (currSum - pre[prevSum]) % 10 < 5 ? (currSum - pre[prevSum]) % 10 : (10 - (currSum - pre[prevSum]) % 10)*-1;
    }
    if(dp[curr][prevSum][d] != INT_MAX) {
        return dp[curr][prevSum][d];
    }
    if(d == 0) {
        return (pre[pre.size()-1] - pre[prevSum]) % 10 < 5 ? (pre[pre.size()-1] - pre[prevSum]) % 10 : (10 - (pre[pre.size()-1] - pre[prevSum]) % 10)*-1;
        
    }
    int temp = currSum + a[curr] - pre[prevSum];
    int saved = temp % 10 < 5 ? (temp % 10) : (10 - (temp % 10))*-1;
    dp[curr][prevSum][d] = max(saved + bt(curr+1, a, d-1, currSum + a[curr], curr+1, dp, pre), bt(curr+1, a, d, currSum+a[curr], prevSum, dp, pre));
    return dp[curr][prevSum][d];
}

int main() {
    int n;
    cin >> n;
    int d;
    cin >> d;
    vector<vector<vector<int>>> dp(n, vector<vector<int>>(n, vector<int>(d+1, INT_MAX)));
    vector<int> pre;
    pre.push_back(0);
    vector<int> a(n);
    int sum = 0;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        sum += a[i];
        pre.push_back(sum);
    }
    cout << sum - bt(0, a, d, 0, 0, dp, pre) << endl;
}