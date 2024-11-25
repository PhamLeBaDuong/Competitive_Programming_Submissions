// #include <math.h>
// #include <iostream>
// #include <unordered_set>
// #include <utility>
// #include <vector>
// #include <unordered_map>
// using namespace std;

// int bt(int i, vector<vector<int>> &arr, int curr, vector<vector<int>> &dp) {
//     if(i >= arr.size()) {
//         return 0;
//     }
//     if(dp[i][curr] != -1) {
//         return dp[i][curr];
//     }
//     dp[i][curr] = 0;
//     if(curr <= arr[i][1] && curr >= arr[i][0]) {
//         dp[i][curr] = max(dp[i][curr], 1 + bt(i+1, arr, curr+1, dp));
//     }
//     dp[i][curr] = max(dp[i][curr], bt(i+1, arr, curr, dp));
//     return dp[i][curr];
// }

// int main(){
//     int n, s;
//     cin >> n >> s;
//     vector<vector<int>> arr;
//     for(int i = 0; i < n; i++) {
//         int a, b;
//         cin >> a >> b;
//         arr.push_back({a,b});
//     }
//     vector<vector<int>> dp(arr.size()+1, vector<int>(s+arr.size()+1,-1));
//     cout << s + bt(0, arr, s, dp);
// }
#include <math.h>
#include <iostream>
#include <unordered_set>
#include <utility>
#include <vector>
#include <unordered_map>
using namespace std;

int bt(int i, vector<vector<int>> &arr, int curr, vector<int> &dp) {
    if(i >= arr.size()) {
        return 0;
    }
    if(dp[i] != -1) {
        return dp[i];
    }
    dp[i] = 0;
    if(curr <= arr[i][1] && curr >= arr[i][0]) {
        dp[i] = max(dp[i], 1 + bt(i+1, arr, curr+1, dp));
    }
    dp[i] = max(dp[i], bt(i+1, arr, curr, dp));
    return dp[i];
}

int main(){
    int n, s;
    cin >> n >> s;
    vector<vector<int>> arr;
    for(int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        arr.push_back({a,b});
    }
    vector<int> dp(arr.size()+1, -1);
    cout << s + bt(0, arr, s, dp);
}