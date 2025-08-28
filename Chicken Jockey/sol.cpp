#include <math.h>
#include <iostream>
#include <unordered_set>
#include <utility>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <queue>
using namespace std;
int main() {
    int t;
    cin >> t;
    while(t--) {
        long long int n;
        cin >> n;
        vector<long long int> arr;
        vector<long long int> dp(n+1, 0);
        for(int i = 0; i < n; i++) {
            int x;
            cin >> x;
            arr.push_back(x);
        }
        dp[1] = arr[0];
        for(long long int i = 2; i <= n; i++) {
            dp[i] = min(dp[i-1] + arr[i-1] - 1, dp[i-2] + arr[i-2] + max((long long int)0, arr[i-1] - (i - 1)));
        }
        cout << dp[n] << endl;
    }
}