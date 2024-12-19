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
    while(t--)  {
        int n, m;
        cin >> n >> m;
        int nn = n;
        int curr = 0;
        int count = 0;
        // priority_queue<int, vector<int>, greater<int>> pq;
        while(nn--) {
            string s;
            cin >> s;
            if(curr + s.size() <= m)
            {
                curr += s.size();
                count++;
            }
            else {
                curr = m+1;
            }
            // pq.push(s.size());
        }
        // while(curr + pq.top() <= m && !pq.empty()) {
        //     curr += pq.top();
        //     count++;
        //     pq.pop();
        // }
        cout << count << endl;
    }
}