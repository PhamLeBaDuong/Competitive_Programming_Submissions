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
int bt(int curr, int i, int j, vector<string> &arr, string &target, vector<vector<int>>&dir, int diri) {
    if(i < 0 || i >= arr.size() || j < 0 || j >= arr[0].size() || arr[i][j] != target[curr]) {
        return 0;
    }
    if(curr >= target.size()-1) {
        // cout << i << " " << j << endl;
        return 1;
    }
    return bt(curr+1, i+dir[diri][0], j+dir[diri][1], arr, target, dir, diri);
    // return bt(curr+1, i+1, j, arr, target) + 
    //         bt(curr+1, i-1, j, arr, target) + 
    //         bt(curr+1, i, j+1, arr, target) + 
    //         bt(curr+1, i, j-1, arr, target) + 
    //         bt(curr+1, i+1, j+1, arr, target) + 
    //         bt(curr+1, i+1, j-1, arr, target) + 
    //         bt(curr+1, i-1, j+1, arr, target) + 
    //         bt(curr+1, i-1, j-1, arr, target);
}
int main() {
    vector<string> arr;
    int res = 0;
    string target = "XMAS";
    while(true) {
        string s;
        cin >> s;
        // cout << s << endl;
        if (s == "0000") {
            break;
        }
        arr.push_back(s);
    }
    vector<vector<int>> dir = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}, {1, 1}, {1, -1}, {-1, 1}, {-1, -1}};
    for(int i = 0; i < arr.size(); i++)  {
        for(int j = 0; j < arr.size(); j++) {
            if(arr[i][j] == 'X') {
                for(int ii = 0; ii < dir.size(); ii++) {
                    res += bt(0, i, j, arr, target, dir, ii);
                }
            }
            // res += bt(0, i, j, arr, target); 
        }
    }
    cout << res << endl;
}
