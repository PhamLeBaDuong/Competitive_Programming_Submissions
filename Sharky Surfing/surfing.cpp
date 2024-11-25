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
        int n, m, l;
        cin >> n >> m >> l;
        vector<vector<int>> pUps;
        vector<vector<int>> hurdles;
        unordered_map<int, int> dp;
        while(n--) {
            int l, r;
            cin >> l >> r;
            hurdles.push_back({l, r});
        }
        while(m--) {
            int l, r;
            cin >> l >> r;
            pUps.push_back({l, r});
        }        
        priority_queue<int, vector<int>, less<int>> pq;
        int j = 0;
        int i = 0;
        int currPower = 1;
        int res = 0;
        while(j < hurdles.size()) {
            while(i < pUps.size() && pUps[i][0] <= hurdles[j][0]) {
                pq.push(pUps[i][1]);
                i++;
            }
            while(currPower <= hurdles[j][1] - hurdles[j][0] + 1 && !pq.empty()) {
                currPower += pq.top();
                res++;
                pq.pop();
            }
            if(pq.empty() && currPower <= hurdles[j][1] - hurdles[j][0] + 1) {
                res = -1;
                break;
            }
            j++;            
        }
        cout << res << endl;
    }
}