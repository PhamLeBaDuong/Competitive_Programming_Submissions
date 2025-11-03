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

int main() {
    int n;
    cin >> n;
    vector<int> distances(n);
    unordered_set<int> distSet;
    // vector<vector<int>> a3 = {{3,0}, {1,2}, {2,1}, {0,3}};
    // vector<vector<int>> aa = {{1,1,1},{2,1,0},{0,1,2},{1,2,0},{0,2,1},{0,3,0}};
    for(int i = 0; i < n; i++) {
        cin >> distances[i];
        distSet.insert(distances[i]);
    }
    int a = distances[0]/3;
    int c = distances[distances.size()-1]/3;
    cout << a << " " << distances[1] - a - a << " " << c << endl;
    // unordered_set<int> tempSet;
    // for(auto &t : a3) {
    //     tempSet.insert(a*t[0] + c*t[1]);
    // }
    // for(int i = a+1; i < c; i++) {
    //     auto temp = tempSet;
    //     for(auto &t : aa) {
    //         int tempRes = a*t[0] + i*t[1] + c*t[2];
    //         if(distSet.find(tempRes) != distSet.end()) {
    //             temp.insert(tempRes);
    //         }
    //     }
    //     if(temp.size() == distSet.size()) {
    //         cout << a << " " << i << " " << c << endl;
    //         return 0;
    //     }
    // }
}
    