#include <math.h>
#include <iostream>
#include <utility>
#include <vector>
#include <queue>
#include <unordered_map>
using namespace std;

bool bt(int i, vector<vector<int>> &dir, pair<int, int> coor, pair<int, int> target) {
    if(i >= dir.size()) {
        return bt(0, dir, coor, target);
    }
    if(coor == target) {
        return true;
    }
    int distance = sqrt(pow(coor.first - target.first, 2) + pow(coor.second - target.second, 2));
    if(distance > 23) {
        return false;
    }
    return bt(i+1, dir, {coor.first + dir[i][0], coor.second + dir[i][1]}, target);
}

int main() {
    int testCases;
    cin >> testCases;
    for(int i = 0; i < testCases; i++) {
        int n, a, b;
        cin >> n >> a >> b;
        string s;
        cin >> s;
        vector<vector<int>> dir;
        vector<int> coor(2, 0);
        for(auto ss : s) {
            if(ss == 'N') {
                dir.push_back({0,1});
                coor[1]++;
            }
            else if(ss == 'S') {
                dir.push_back({0,-1});
                coor[1]--;
            }
            else if(ss == 'E') {
                dir.push_back({1,0});
                coor[0]++;
            }
            else {
                dir.push_back({-1,0});
                coor[0]--;
            }
        }
        cout << ((coor[0] != 0 || coor[1] != 0) && bt(0, dir, {0,0}, {a,b}) ? "YES" : "NO") << endl;
        // double slope;
        // double sloperes;
        // if(coor[0] == 0) {
        //     slope = INT_MAX;
        // }
        // else {
        //     slope = (double)coor[1] / (double)coor[0];
        // }
        // if(a == 0) {
        //     sloperes = INT_MAX;
        // }
        // else {
        //     sloperes = (double)b / (double)a;
        // }
        // double distance1 = sqrt(pow(coor[0],2) + pow(coor[1],2));
        // double distance2 = sqrt(pow(a, 2) + pow(b, 2));
        // cout << slope << " " << sloperes << " " << distance1 << " " << distance2 << " " << fmod(distance2, distance1) << endl;
        // if(slope == sloperes && fmod(distance2, distance1) == 0) {
        //     cout << "YES" << endl;
        // }
        // else {
        //     cout << "NO" << endl;
        // }
    }
}