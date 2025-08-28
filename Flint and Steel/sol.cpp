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
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        vector<int> arr(n);
        vector<int> det(n);
        for(int i = 0; i < n; i++) {
            cin >> arr[i];
            det[i] = arr[i];
        }
        det[0] = arr[0] == 0 ? -1 : 1;
        for(int i = 1; i < n; i++) {
            if(i - arr[i] + 1 <= 0) {
                // cout << " o:" << i << ":o ";
                // cout << i - arr[0] - 1 << " ";
                det[i] = 1;
                // cout << det[i];
                continue;
            }
            if(arr[i] == 0) {
                det[i] = -1;
                continue;
            }
            int temp = INT_MAX;
            for(int j = 0; j < i; j++) {
                if(det[j] == -1) {continue;}
                // if(j + arr[j] - 1 >= i - arr[i] && j + arr[j] - 1 < i) {
                if(j + arr[j] - 1 >= i - arr[i]) {
                    if(j + arr[j] - 1 >= i && i - arr[i] + 1 <= j) {
                        continue;
                    }
                    temp = min(temp, det[j] + 1);
                }
                // else if(j + arr[j] >= i) {
                //     temp = min(temp, det[j]);
                // }
            }
            det[i] = (temp == INT_MAX ? -1 : temp);
        }

        
        int res = INT_MAX;
        int curr = n-1;
        unordered_map<int, int> mp;
        
        // cout << endl;
        for(int i = 0; i < n; i++) {
            // cout << det[i] << " ";
            if(det[i] == -1) continue;
            if(i + arr[i] - 1 >= n - 1) { // can reach the end
                if(det[i] < res) {
                    curr = i;
                    res = det[i];
                }
            }
        }
        // cout << endl;
        if(res == INT_MAX) {
            cout << -1 << endl;
            continue;
        }
        vector<int> ans(res);
        // ans.push_back(curr + 1);
        mp[curr+1] = res;
        cout << res << endl;
        int maxx = res-1;
        for(int i = curr-1; i >= 0; i--) {
            if(det[i] == -1) { // unreachable
                // cout << i << " ";
                continue;
            }
            if(maxx != det[i]) { // not part of the optimal solution
                // cout << i << " ";
                continue;
            }
            if(!(i + arr[i] - 1 >= curr - arr[curr])) { // does not reach the current position
            // if(!(i + arr[i] - 1 >= curr - arr[curr] && i + arr[i] - 1 < curr)) { // does not reach the current position
                // cout << i << " ";
                continue;
            }
            if(i + arr[i] - 1 >= curr) {
            // if(i + arr[i] - 1 >= curr && curr - arr[curr] + 1 <= i) {
                if(curr - arr[curr] + 1 <= i) {
                    continue;
                }
                // auto temp = mp[curr];
                mp[i+1] = mp[curr+1];
                mp[curr+1] = maxx;
                // ans.push_back(ans[ans.size() - 1]);
                // ans[ans.size() - 2] = i + 1;
                curr = i;
                maxx--;
                continue;
                // cout << i << " ";
            }
            mp[i+1] = maxx;
            // ans.push_back(i + 1);
            curr = i;
            maxx--;
        }
        for(auto &x : mp) {
            ans[x.second - 1] = x.first;
        }
        // cout << endl;
        for(int i = 0; i < ans.size(); i++) {
        // for(int i = ans.size() - 1; i >= 0; i--) {
            cout << ans[i] << " ";
        }
        cout << endl;
    }
}