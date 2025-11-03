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
int main() {
    int r, c, gr, gc, lr, lc;
    while(cin >> r >> c >> gr >> gc >> lr >> lc){
        vector<vector<int>> dp(r, vector<int>(c, INT_MAX));
        gr--; gc--; lr--; lc--;
        dp[gr][gc] = 0;
        vector<vector<int>> dirs = {{2,1}, {2,-1}, {-2,1}, {-2,-1}, {1,2}, {1,-2}, {-1,2}, {-1,-2}};
        priority_queue<pipii, vector<pipii>, greater<pipii>> pq;
        pq.push({{gr, gc}, 0});
        queue<pipii> q;
        q.push({{gr, gc}, 0});
        int count = 0;
        bool flag = false;
        while(!q.empty()) {
            int t = q.size();
            while(t--) {
                auto temp = q.front();
                q.pop();
                int cr = temp.first.first;
                int cc = temp.first.second;
                int cd = temp.second;
                if(cr == lr && cc == lc) {
                    cout << count << endl;
                    flag = true;
                    break;
                }
                for(auto &i : dirs) {
                    int nr = cr + i[0];
                    int nc = cc + i[1];
                    if(nr >= 0 && nr < r && nc >= 0 && nc < c) {
                        if(cd + 1 < dp[nr][nc]) {
                            dp[nr][nc] = cd + 1;
                            q.push({{nr, nc}, cd + 1});
                        }
                    }
                }
            }
            count++;
        }
        // while(!pq.empty()) {
        //     auto temp = pq.top();
        //     pq.pop();
        //     int cr = temp.first.first;
        //     int cc = temp.first.second;
        //     int cd = temp.second;
        //     if(cr == lr && cc == lc) {
        //         cout << cd << endl;
        //         break;
        //     }
        //     for(auto &i : dirs) {
        //         int nr = cr + i[0];
        //         int nc = cc + i[1];
        //         if(nr >= 0 && nr < r && nc >= 0 && nc < c) {
        //             if(cd + 1 < dp[nr][nc]) {
        //                 dp[nr][nc] = cd + 1;
        //                 pq.push({{nr, nc}, cd + 1});
        //             }
        //         }
        //     }
        // }
        if(!flag) {
            cout << "impossible" << endl;
        }
    }
}