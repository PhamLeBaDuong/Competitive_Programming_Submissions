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

// class DisjointSets
// {
// private:
//     vector<int> parents;
//     vector<int> sizes;
//     int count;

// public:
//     DisjointSets(int size) : parents(size), sizes(size, 1)
//     {
//         for (int i = 0; i < size; i++)
//         {
//             parents[i] = i;
//         }
//         count = size;
//     }

//     /** @return the "representative" node in x's component */
//     int find(int x) { return parents[x] == x ? x : (parents[x] = find(parents[x])); }

//     /** @return whether the merge changed connectivity */
//     bool unite(int x, int y)
//     {
//         // count++;
//         int x_root = find(x);
//         // if(x_root == x) {
//         //     count++;
//         // }
//         int y_root = find(y);
//         // if(y_root == y) {
//         //     count++;
//         // }
//         if(x_root == x && y_root == y && sizes[x_root] == 1 && sizes[y_root] == 1) {
//             count++;
//         }
//         if (x_root == y_root)
//         {
//             // count--;
//             return false;
//         }
        
//         if (sizes[x_root] < sizes[y_root])
//         {
//             swap(x_root, y_root);
//         }
//         sizes[x_root] += sizes[y_root];
//         parents[y_root] = x_root;
//         return true;
//     }

//     /** @return whether x and y are in the same connected component */
//     bool connected(int x, int y) { return find(x) == find(y); }

//     int getCount() { return count; }
// };

bool u(int x, int y, vector<int> &p, vector<int> &assign, int &count, int val) {
    int resX = find(x, p);
    int resY = find(y, p);
    if(resX == resY) {
        return;
    }
    if(assign[resX] == -1 && assign[resY] == -1) {
        assign[resX] == val;
    }
    else {
        if(val != -1) {
            if((assign[resX] != -1 && assign[resX] != val) || (assign[resY] != -1 && assign[resY] != val)) {
                return false;
            }
            else {
                assign[resX] = val;
            }
        }
    }
    if(p[resX] == -1 || p[resY] == -1) {
        if(p[resX] == -1 && p[resY] == -1) {
            count++;
        }
    }
    else {
        count--;
    }
    p[resX] += p[resY];
    p[resY] = resX;
    return true;
}

int find(int x, vector<int> &p) {
    if(p[x] < 0) {
        return x;
    }
    int res = find(p[x], p);
    p[x] = res;
    return res;
}

long long int powMod(long long int a, long long int b, long long int modd) {
    long long int res = 1;
    while(b > 0) {
        if(b & 1) {
            res = (res * a) % modd;
        }
        a = (a * a) % modd;
        b >>= 1;
    }
    return res;
}

int bt(int curr, int modd, int target, vector<int> &a, unordered_map<int, vector<int>> &mp, vector<bool> &visited, int currVal, int &count, vector<int> &assign) {
    if(visited[curr]) {
        return -2;
    }
    visited[curr] = true;
    if(a[curr] != -1) {
        if(a[curr] != currVal) {
            return -3;
        }
        return -2;
    }
    if(curr == target) {
        return a[curr] == -1 ? curr : -1;
    }
    for(auto &edge : mp[curr]) {
        int res = bt(edge, modd, target, a, mp, visited, currVal, count, assign);
        // if(res == -3) {
        //     return -3;
        // }
        if(res == -1) {
            return a[curr] == -1 ? curr : -1;
        }
        if(res > -1) {
            if(a[curr] == -1) {
                u(curr, res, a, assign, count, currVal);
                return curr;
            }
            return res;
        }
    }
    return -3;
}

int main()
{
    int t;
    cin >> t;
    int modd = 998244353;
    while (t--)
    {
        int n, m, v;
        cin >> n >> m >> v;
        // DisjointSets dsu(n);
        vector<int> a(n);
        for(int i = 0; i < n; i++) {
            cin >> a[i];
        }
        unordered_map<int, vector<int>> mp;
        vector<pair<int, int>> edges;
        while(m--) {
            int a, b;
            cin >> a >> b;
            if(mp[a].size() != 0 && mp[b].size() != 0) {
                edges.push_back({a,b});
            }
            else {
                mp[a].push_back(b);
                mp[b].push_back(a);
            }
        }
        long long int res = 0;
        int count = 0;
        vector<int> assign(n, -1);
        for(int i = 0; i < edges.size(); i++) {
            vector<bool> visited(n, false);
            bt(edges[i].first, modd, edges[i].second, a, mp, visited, a[edges[i].first], count, assign);
        }
        cout << powMod(v, count, modd) << endl;
    }
}