#include <math.h>
#include <iostream>
#include <string>
#include <utility>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <queue>
#include <bits/stdc++.h>
#include <unordered_set>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while(t--) {
        int n, k;
        cin >> n >> k;
        vector<int> a(n);
        unordered_map<int, int> mp;
        for(int i = 0; i < n; i++) {
            cin >> a[i];
            mp[a[i]]++;
        }
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        for(auto i:mp) {
            pq.push({i.second, i.first});
        }
        while(pq.top().first <= k) {
            k -= pq.top().first;
            mp.erase(pq.top().second);
            pq.pop();
        }
        cout << max(1, (int)mp.size()) << endl;
    }
}