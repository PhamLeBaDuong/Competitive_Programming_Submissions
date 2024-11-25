#include <math.h>
#include <iostream>
#include <string>
#include <utility>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <queue>
using namespace std;
int main() {
    int t;
    cin >> t;
    while (t--)  {
        int n, k;
        cin >> n >> k;
        unordered_map<int, int> mp;
        for(int i =0; i < k; i++) {
            int b, c;
            cin >> b >> c;
            mp[b] += c;
        }
        priority_queue<pair<int, int> , vector<pair<int, int>>, less<pair<int, int>>> pq;
        for(auto it : mp) {
            pq.push({it.second, it.first});
        }
        int res = 0;
        int count = 0;
        while(!pq.empty() && count < n) {
            res += pq.top().first;
            pq.pop();
            count++;
        }
        cout << res << endl;
    }
}