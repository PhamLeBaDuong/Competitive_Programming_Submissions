#include <math.h>
#include <iostream>
#include <unordered_set>
#include <utility>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <queue>
using namespace std;
void bt(unordered_map<int, vector<int>> &mp, int curr, int prev, vector<int> &visited, int prevCut, int &numCut) {
    if(visited[curr] != -1) {
        return;
    }
    // cout << curr << mp[curr].size() << " " << prev << endl;
    if((int)mp[curr].size() - prevCut <= 2) {
        if(visited[prev] == 1) {
            visited[prev] = 2;
        }
        visited[curr] = 1;
        // visited[prev] = 2;
        bt(mp, mp[curr][0] == curr ? mp[curr][1] : mp[curr][0], curr, visited, 0, numCut);
    }
    // else if(mp[curr].size() == 3) {
    //     visited[prev] = 0;
    //     cout << "2 " << prev << endl;
    //     visited[curr] = 1;
    //     for(auto &i : mp[curr]) {
    //         if(i != prev) {
    //             bt(mp, i, curr, visited);
    //         }
    //     }
    // }
    else {
        visited[curr] = 0;
        numCut++;
        // cout << "2 " << curr << endl;
        for(auto &i : mp[curr]) {
            if(i != prev) {
                bt(mp, i, curr, visited, 1, numCut);
            }
        }
    }
    // else if()
    // if(prev == 2) {
    //     cout << "2 " << curr << endl;
    //     visited[curr] = true;
    //     prev = 0;
    // }
    // prev++;
    // for(auto &i : mp[curr]) {
    //     bt(mp, i, prev, visited);
    // }
}

void checkNode(unordered_map<int, vector<int>> &mp, int curr, vector<int> &visited) {
    if(visited[curr] < 1) {
        return;
    }
    cout << "1 " << curr << endl;
    visited[curr] = -1;
    for(auto &i : mp[curr]) {
        checkNode(mp, i, visited);
    }
}

int main() {
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        vector<int> visited(n+1, -1);
        unordered_map<int, vector<int>> mp;
        n--;
        while(n--) {
            int a, b;
            cin >> a >> b;
            mp[a].push_back(b);
            mp[b].push_back(a);
        }
        int st = 0;
        for(auto &i : mp) {
            if(i.second.size() == 1) {
                st = i.first;
                break;
            }
        }
        cout << endl;
        cout << st << endl;
        int numCut = 0;
        bt(mp, st, 0, visited, 0, numCut);
        cout << numCut + visited.size()-1 << endl;
        for(int i = 1; i < visited.size(); i++) {
            if(visited[i] == 0) {
                cout << "2 " << i << endl;
            }
            // cout << visited[i] << " ";
        }


        // cout << endl;
        for(int i = 1; i < visited.size(); i++) {
            if(visited[i] == 1) {
                checkNode(mp, i, visited);
            }
            else if(visited[i] != 2) {
                cout << "1 " << i << endl;
            }
        }
        // cout << endl;

    }
}