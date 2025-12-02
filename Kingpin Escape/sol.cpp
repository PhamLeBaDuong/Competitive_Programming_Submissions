#include <math.h>
#include <iostream>
#include <unordered_set>
#include <utility>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

void dfs(int node, int parent, vector<vector<int>>& adj, unordered_set<int> &st) {
    // cout << "wth";
    if(adj[node].size() == 1) {
        st.insert(node);
        return;
    }
    for(int neighbor : adj[node]) {
        if(neighbor != parent) {
            dfs(neighbor, node, adj, st);
        }
    }
}

int main() {
    int n, h;
    cin >> n >> h;
    vector<vector<int>> adj(n);
    for(int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vector<unordered_set<int>> st;
    for(auto &i : adj[h]) {
        unordered_set<int> temp;
        dfs(i, h, adj, temp);
        st.push_back(temp);
    }
    sort(st.begin(), st.end(), [](const unordered_set<int>& a, const unordered_set<int>& b) {
        return a.size() > b.size();
    });
    vector<vector<int>> res;
    int i = 0;
    int j = st.size()-1;
    int bruh = (h);
    if(st.size() == 1 && st[0].size()%2 == 0) {
        res.push_back({h, *st[0].cbegin()});
    }
    while(i <= j) {
        vector<int> temp;
        if(i == j && st[i].size() == 1) {
        // if(i == j) {
            // if(st[i].size() == 1) {
                temp.push_back(bruh);
                temp.push_back(*st[i].begin());
                st[i].erase(*st[i].begin());
                res.push_back(temp);
            // }
            // else {
            //     temp.push_back(*st[i].begin());
            //     st[i].erase(*st[i].begin());
            //     temp.push_back(*st[i].begin());
            //     st[i].erase(*st[i].begin());
            //     res.push_back(temp);
            // }
        }
        else {
            temp.push_back(*st[i].begin());
            st[i].erase(*st[i].begin());
            temp.push_back(*st[j].begin());
            st[j].erase(*st[j].begin());
            res.push_back(temp);
        }
        if(st[i].empty()) {
            i++;
        }
        if(st[j].empty()) {
            j--;
        }
    }
    cout << res.size() << "\n";
    for(auto &i : res) {
        cout << i[0] << " " << i[1] << "\n";
    }
}
/*
9 0
0 1
1 2
1 3
1 4
1 5
1 6
0 7
0 8
*/