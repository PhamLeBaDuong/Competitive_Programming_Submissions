#include <math.h>
#include <iostream>
#include <unordered_set>
#include <utility>
#include <vector>
#include <unordered_map>
#include <iomanip>
#include <algorithm>
#include <map>
#include <queue>
using namespace std;

vector<unordered_map<string, double>> dp;
unordered_map<int, vector<vector<int>>> mp;
unordered_map<int, double> mp2;
vector<vector<int>> list_edges;
string visited;
vector<vector<int>> adj_list;
int x;

double dfs(int curr, double curr_product = 1) {
    double res = 1;
    if(dp[curr][visited] != 0) {
        return dp[curr][visited];
    }
    if(curr_product < 1e-6) return 0;
    for(auto &next : adj_list[curr]) {
        if(visited[next] == '1') {
            continue;
        }
        visited[next] = '1';
        res += (1/(double)adj_list[next].size())*dfs(next, curr_product/(double)adj_list[next].size());
        visited[next] = '0';
    }
    dp[curr][visited] = res;
    return res;
}

int main() {
    int n, m;
    cin >> n >> m;
    adj_list.resize(n+1);
    list_edges.resize(m, vector<int>(2));

    for(int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adj_list[u].push_back(v);
        adj_list[v].push_back(u);
        list_edges[i][0] = u;
        list_edges[i][1] = v;
    }
    cin >> x;
    dp.resize(n+1);
    visited.resize(n+1, '0');
    visited[x] = '1';
    cout.setf(std::ios::fixed);
    cout << setprecision(1) << dfs(x) << endl;
}