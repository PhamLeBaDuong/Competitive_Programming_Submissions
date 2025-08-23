#include <math.h>
#include <iostream>
#include <string>
#include <utility>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <queue>
#include <unordered_set>
#include <map>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    vector<int> pos(n + 1);
    for (int i = 0; i < n; i++) {
        int temp;
        cin >> temp;
        pos[temp] = i;
    }
    vector<int> dp;
    int res = 0;
    for(int i : a) {
        int idx = lower_bound(dp.begin(), dp.end(), pos[i]) - dp.begin();
        if(idx == dp.size()) {
            dp.push_back(pos[i]);
        } else {
            dp[idx] = pos[i];
        }
    }
    cout << dp.size() << endl;
    return 0;  
}