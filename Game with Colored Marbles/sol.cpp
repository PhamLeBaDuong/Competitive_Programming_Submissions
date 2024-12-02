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
    while (t--) {
        int n;
        cin >> n;
        unordered_map<int, int> mp;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        for(int i = 0; i < n; i++) {
            int a;
            cin >> a;
            mp[a]++;
        }
        for(auto i : mp) {
            pq.push({i.second, i.first});
        }
        int nalc = n/2 + n%2;
        int alc = 0;
        int countalc = 0;
        while(true) {
            // cout << pq.top().first << " " << pq.top().second << endl;
            if(pq.top().first == 1) {
                alc += 2;
                countalc++;
                if(countalc == nalc) {
                    break;
                }
                pq.pop();
            }
            else {
                if(pq.size() > nalc-countalc) {
                    alc += nalc-countalc;
                }
                else {
                    alc += pq.size();
                    countalc += pq.size();
                    while(pq.top().first-1 <= nalc-countalc) {
                        // cout << pq.top().first << " " << pq.top().second << endl;
                        countalc += pq.top().first-1;
                        alc++;
                        pq.pop();
                    }
                }
                // alc += min(nalc-countalc,(int)(pq.size()));
                break;
            }
        }
        cout << alc << endl;
    }
}