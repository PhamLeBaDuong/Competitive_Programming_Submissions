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
typedef long long int lli;

bool dfs(vector<string> &maze, int i, int j, int iend, int jend, vector<vector<vector<bool>>> &visited, int dir, vector<vector<int>> &dirs) {
    if(iend == i && jend == j) {
        return true;
    }
    if(visited[i][j][dir]) {
        return false;
    }
    visited[i][j][dir] = true;
    int leftDir = (dir+1)%4;
    int leftCellI = i + dirs[leftDir][0];
    int leftCellJ = j + dirs[leftDir][1];
    if(leftCellI >= 0 && leftCellI < maze.size() && leftCellJ >= 0 && leftCellJ < maze[0].size() && maze[leftCellI][leftCellJ] == '0') {
        return dfs(maze, leftCellI, leftCellJ, iend, jend, visited, leftDir, dirs);
    }

    int fwdCellI = i + dirs[dir][0];
    int fwdCellJ = j + dirs[dir][1];
    if(fwdCellI >= 0 && fwdCellI < maze.size() && fwdCellJ >= 0 && fwdCellJ < maze[0].size() && maze[fwdCellI][fwdCellJ] == '0') {
        return dfs(maze, fwdCellI, fwdCellJ, iend, jend, visited, dir, dirs);
    }

    return dfs(maze, i, j, iend, jend, visited, (dir-1+4)%4, dirs);
}

int main() {
    int r, c, istart, jstart, iend, jend;
    cin >> r >> c >> istart >> jstart >> iend >> jend;
    vector<string> maze(r, string(c, '0'));
    for(int i = 0; i < r; i++) {
        for(int j = 0; j < c; j++) {
            cin >> maze[i][j];
        }
    }
    vector<vector<int>> dirs = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}};
    vector<vector<vector<bool>>> visited(r, vector<vector<bool>>(c, vector<bool>(4, false)));
    cout << (dfs(maze, istart-1, jstart-1, iend-1, jend-1, visited, 3, dirs) ? "1" : "0") << endl;
}
