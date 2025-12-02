#include <math.h>
#include <iostream>
#include <unordered_set>
#include <utility>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <iomanip>
using namespace std;

double distance_point_to_line(vector<int> &A, vector<int> &B, vector<int> &P) {
    double a = B[1] - A[1];
    double b = A[0] - B[0];
    double c = (double)B[0] * A[1] - (double)A[0] * B[1];

    return fabs(a * P[0] + b * P[1] + c) / sqrt(a * a + b * b);
}

double cross_product(vector<int> &A, vector<int> &B, vector<int> &C) {
    return (double)(B[0] - A[0]) * (C[1] - A[1]) - (double)(B[1] - A[1]) * (C[0] - A[0]);
}

vector<vector<int>> convex_hull_monotone(vector<vector<int>> A) {
    int n = A.size();
    vector<vector<int>> ans;
    sort(A.begin(), A.end());

    // Build lower hull
    for (int i = 0; i < n; ++i) {
        while (ans.size() >= 2 && cross_product(ans[ans.size()-2], ans[ans.size()-1], A[i]) <= 0)
            ans.pop_back();
        ans.push_back(A[i]);
    }

    // Build upper hull
    int lower_size = ans.size();
    for (int i = n - 2; i >= 0; --i) {
        while (ans.size() > lower_size && cross_product(ans[ans.size()-2], ans[ans.size()-1], A[i]) <= 0)
            ans.pop_back();
        ans.push_back(A[i]);
    }

    // Remove the last point because it's the same as the first
    ans.pop_back();
    
    return ans;
}

int main() {
    int n;
    cin >> n;
    vector<vector<int>> a(n, vector<int>(2));
    for(int i = 0; i < n; i++) {
        cin >> a[i][0] >> a[i][1];
    }
    auto convex = convex_hull_monotone(a);
    int curr = 2;
    int curr_prev = (curr - 1 + convex.size()) % convex.size();
    int curr_next = (curr + 1) % convex.size();
    double min_dist = numeric_limits<double>::max();
    if(convex.size() > 3) {
        for(int i = 0; i < convex.size(); i++) {
            int ii = (i + 1) % convex.size();
            while(distance_point_to_line(convex[i], convex[ii], convex[curr_next]) >= distance_point_to_line(convex[i], convex[ii], convex[curr]) && curr != i && curr_next != i) {
                curr = curr_next;
                curr_next = (curr + 1) % convex.size();
            }
            min_dist = min(min_dist, distance_point_to_line(convex[i], convex[ii], convex[curr]));
        }
    }
    else if(convex.size() == 3){
        min_dist = distance_point_to_line(convex[0], convex[1], convex[2]);
        min_dist = min(min_dist, distance_point_to_line(convex[1], convex[2], convex[0]));
        min_dist = min(min_dist, distance_point_to_line(convex[2], convex[0], convex[1]));
    }
    else {
        min_dist = 0;
    }
    cout.setf(std::ios::fixed);
    cout << setprecision(6) << min_dist << "\n";
}