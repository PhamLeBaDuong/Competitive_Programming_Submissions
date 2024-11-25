#include <math.h>
#include <iostream>
#include <string>
#include <utility>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <queue>
using namespace std;
int bt(int curr, int i, vector<int> &list, vector<vector<int>> &dp) {
    if(i > list.size()) {
        return 0;
    }
    int res = INT_MAX;
    if(dp[i][curr] != -1){
        return dp[i][curr];
    }
    if(curr > list[i])
    {
        res = 1 + min(bt(curr, i+1, list, dp), bt(list[i], i+1, list, dp));
    }
    else {
        res = bt(list[i], i+1, list, dp);
    }
    dp[i][curr] = res;
    return res;

}
int main() {
    int t;
    cin >> t;
    while (t--)  {
        int n;
        cin >> n;
        int curr = INT_MIN;
        int res = 0;
        vector<int> list;
        vector<vector<int>> dp(n+1, vector<int>(51, -1));
        while(n--) {
            int h;
            cin >> h;
            list.push_back(h);
        }
        cout << bt(list[0], 0, list, dp) << endl;
    }
}