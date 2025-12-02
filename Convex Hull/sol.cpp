#include <math.h>
#include <iostream>
#include <unordered_set>
#include <utility>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

vector<vector<int>> convex_hull(vector<vector<int>> &points) {
    int temp_i = 0;
    for(int i = 1; i < points.size(); i++) {
        if(points[i][1] < points[temp_i][1]) {
            temp_i = i;
        }
        else if(points[i][1] == points[temp_i][1]) {
            if(points[i][0] >= points[temp_i][0]) {
                temp_i = i;
            }
        }
    }
    int temp_x = points[temp_i][0];
    int temp_y = points[temp_i][1];
    points.erase(points.begin() + temp_i);
    sort(points.begin(), points.end(), [&](const vector<int>& a, const vector<int>& b) {
        double angle_a = atan2(a[1] - temp_y, a[0] - temp_x);
        double angle_b = atan2(b[1] - temp_y, b[0] - temp_x);
        double dist_a = pow(a[1] - temp_y, 2) + pow(a[0] - temp_x, 2);
        double dist_b = pow(b[1] - temp_y, 2) + pow(b[0] - temp_x, 2);
        if(angle_a == angle_b) {
            return dist_a < dist_b;
        }
        return angle_a < angle_b;
    });
    vector<vector<int>> hull;
    hull.push_back({temp_x, temp_y});
    for(int i = 0; i < points.size(); i++) {
        if(points[i][0] == hull.back()[0] && points[i][1] == hull.back()[1]) {
            continue;
        }
        while(hull.size() >= 2) {
            vector<int> p2 = hull.back();
            hull.pop_back();
            vector<int> p1 = hull.back();
            int cross = (p2[0] - p1[0]) * (points[i][1] - p1[1]) - (p2[1] - p1[1]) * (points[i][0] - p1[0]);
            if(cross > 0) {
                hull.push_back(p2);
                break;
            }
        }
        hull.push_back(points[i]);
    }
    return hull;
}   

int main() {
    while(true) {
        int n;
        cin >> n;
        if(n == 0) {
            break;
        }
        vector<vector<int>> a(n, vector<int>(2));
        for(int i = 0; i < n; i++) {
            cin >> a[i][0] >> a[i][1];
        }
        auto res = convex_hull(a);
        cout << res.size() << "\n";
        for(auto &i : res) {
            cout << i[0] << " " << i[1] << "\n";
        }
    }
}