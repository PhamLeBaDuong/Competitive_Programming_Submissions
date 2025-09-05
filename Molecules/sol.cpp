#include <math.h>
#include <iostream>
#include <string>
#include <utility>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <queue>
using namespace std;
typedef long long int lli;
typedef pair<double, double> pii;

// Overload the stream insertion operator for pii
std::ostream& operator<<(std::ostream& os, const pii& p) {
    os << "(" << p.first << ", " << p.second << ")";
    return os;
}

pii bt(int curr, vector<bool> &visited, vector<pii> &a, unordered_map<int, vector<int>> &mp, pii prevPos, int prevCount) {
    if(visited[curr]) {
        return {-2, -2};
    }
    cout << curr << " | " << prevPos.first << ", " << prevPos.second << " | " << prevCount << endl;
    bool flag = false;
    visited[curr] = true;
    for(auto &i : mp[curr]) {
        auto res = bt(i, visited, a, mp, prevPos, prevCount + 1);
        if(a[curr].first != -1 || res.first == -2) {
            continue;
        }
        if(res.first != -1) {
            a[curr] = {(prevPos.first + res.first) / 2.0, (prevPos.second + res.second) / 2.0};
            flag = true;
            prevCount = 0;
            prevPos = a[curr];
        }
        else if(res.first == -1) {
            a[curr] = {prevPos.first, prevPos.second + prevCount};
            flag = true;
            prevCount = 0;
            prevPos = a[curr];
        }
    }
    return a[curr];
}

int main() {
    int n, m;
    cin >> n >> m;
    vector<pii> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i].first >> a[i].second;
    }
    unordered_map<int, vector<int>> mp;
    for (int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        mp[x-1].push_back(y-1);
        mp[y-1].push_back(x-1);
    }
    cout << endl;
    vector<bool> visited(n, false);
    for(int i = 0; i < n; i++) {
        if(!visited[i] && a[i].first != -1) {
            bt(i, visited, a, mp, a[i], 0);
        }
    }
    cout << endl;
    for(auto &i : a) {
        cout << i.first << " " << i.second << endl;
    }
}