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
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        string s;
        for(int i = 1; i <= n; i++) {
            s += to_string(i) + " ";
        }
        s.pop_back();
        priority_queue<pair<int, int>, vector<pair<int, int>>, less<pair<int, int>>> pq;
        for(int i = 1; i <= n; i++) {
            cout << "? " << i << " " << n << " " << s << endl;
            fflush(stdout);
            int x;
            cin >> x;
            pq.push({x,i});
        }
        int maxi = pq.top().first;
        int temp = maxi;
        string res = "";
        int prev = -1;
        while(!pq.empty() && maxi > 0) {
            if(prev != -1) {
                cout << "? " << pq.top().second << " " << 2 << " " << prev << " " << pq.top().second << endl;
                fflush(stdout);
                int x;
                cin >> x;
                // cout.flush();
                if(x == 2) {
                    res += to_string(pq.top().second) + " ";
                    prev = pq.top().second;
                    maxi--;
                }
                else {

                }
            }
            else {
                res += to_string(pq.top().second) + " ";
                prev = pq.top().second;
                maxi--;
            }
            pq.pop();
        }
        res.pop_back();
        cout << "! " << temp << " " << res << endl;
        fflush(stdout);
        // cout.flush();
        // cout << s << endl;
    }
}