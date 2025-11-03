#include <math.h>
#include <iostream>
#include <unordered_set>
#include <utility>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <queue>
using namespace std;
int main()
{
    int r, c, n;
    cin >> r >> c >> n;
    vector<vector<int>> a(n, vector<int>(2, 0));
    queue<vector<int>> q;
    vector<vector<vector<int>>> grid(r, vector<vector<int>>(c));
    for (int i = 0; i < n; i++)
    {
        cin >> a[i][0] >> a[i][1];
        q.push({a[i][0] - 1, a[i][1] - 1, i+1});
        grid[a[i][0] - 1][a[i][1] - 1].push_back(i+1);
    }
    vector<vector<int>> dirs = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    while(!q.empty()) {
        int t = q.size();
        while(t--) {
            auto curr = q.front();
            q.pop();
            for(auto &dir : dirs) {
                int i = curr[0] + dir[0];
                int j = curr[1] + dir[1];
                if(i < 0 || i >= r || j < 0 || j >= c || grid[i][j].size() >= 2 || (grid[i][j].size() > 0 && grid[i][j][0] == curr[2])) {
                    continue;
                } 
                grid[i][j].push_back(curr[2]);
                q.push({i, j, curr[2]});
            }
        }
    }

    for(int i = 0; i < r; i ++) {
        for(int j = 0; j < c; j ++) {
            cout << grid[i][j][0] << " ";
        }
        cout << "\n";
    }
    for(int i = 0; i < r; i ++) {
        for(int j = 0; j < c; j ++) {
            cout << grid[i][j][1] << " ";
        }
        cout << "\n";
    }

}