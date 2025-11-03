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

int bt(int curr, vector<pair<int, string>> &a, int path, int target, unordered_map<int, int> &dp) {
    if(path == target) {
        return 0;
    }
    if(curr >= a.size()) {
        return 9000;
    }
    if(dp.find(path) != dp.end()) {
        return dp[path];
    }
    // int include = bt(curr + 1, a, path | (1 << (a[curr].second[0] - 'a')), target) + a[curr].first;
    // int include = 0;
    auto temp = path;
    for(auto &i : a[curr].second) {
        temp = temp | (1 << (i - 'a'));
        // include = bt(curr + 1, a, path | (1 << (i - 'a')), target) + a[curr].first;
    }
    int include = bt(curr + 1, a, temp, target, dp) + a[curr].first;
    int exclude = bt(curr + 1, a, path, target, dp);
    dp[path] = min(include, exclude);
    return min(include, exclude);
}

int main() {
    int n;
    // vector<int> (9);
    cin >> n;
    vector<pair<int, string>> a(n);
    int target = 0;
    for(int i = 0; i < n; i++) {
        cin >> a[i].first;
        cin >> a[i].second;
        for(auto &j : a[i].second) {
            target = target | (1 << (j - 'a'));
        }
    }
    unordered_map<int, int> dp;
    cout << bt(0, a, 0, target, dp) << endl;
}