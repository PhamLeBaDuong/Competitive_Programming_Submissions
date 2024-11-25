#include <math.h>
#include <iostream>
#include <utility>
#include <vector>
#include <queue>
#include <unordered_map>
using namespace std;

void bt(int &i, int curr, unordered_map<int, priority_queue<int, vector<int>, greater<int>>> &mp, vector<vector<int>> &list) {
    list[curr][0] = i;
    while(!mp[curr].empty()) {
        i++;
        bt(i, mp[curr].top(), mp, list);
        mp[curr].pop();
    }
    list[curr][1] = i;
}

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> list(n+1, vector<int>(2, 0));
    unordered_map<int, priority_queue<int, vector<int>, greater<int>>> mp;
    for(int i = 1; i < n; i++) {
        int a, b;
        cin >> a >> b;
        mp[a].push(b);
    }
    vector<int> people;
    for(int i = 0; i < m; i++) {
        int d;
        cin >> d;
        people.push_back(d);
    }
    int count;
    bt(count,1,mp,list);
    int maxx = -1;
    int res = 0;
    for(auto i : people) {
        maxx = max(maxx, list[i][0]);
        if(maxx > list[i][1]) {
            break;
        }
        else {
            res++;
        }
    }
    cout << res;
}

// #include <math.h>
// #include <iostream>
// #include <utility>
// #include <vector>
// #include <queue>
// #include <unordered_map>
// #include <set>
// using namespace std;

// int bt(int i, vector<int> &people, int curr, 
//         unordered_map<int, priority_queue<int, vector<int>, greater<int>> > & mp, 
//         vector<vector<int>> &dp, set<pair<int, int>> &visited) {
//     // cout << curr << " " << i << endl;
//     if(i >= people.size()) {
//         return 0;
//     }
//     if(dp[i][curr] != -1) {
//         return dp[i][curr];
//     }
//     dp[i][curr] = 0;
//     // int res = 0;
//     if(curr == people[i]) {
//         dp[i][curr] = 1 + bt(i+1, people, 1, mp, dp, visited);
//         return dp[i][curr];
//     }
//     else {
//         // auto temp = mp;
//         // while(!temp[curr].empty()) {
//         //     dp[i][curr] = max(dp[i][curr], bt(i, people, temp[curr].top(), temp, dp));
//         //     temp[curr].pop();
//         // }
//         while(!mp[curr].empty()) {
//             if(visited.find({curr, mp[curr].top()}) == visited.end()) {
//                 dp[i][curr] = max(dp[i][curr], bt(i, people, mp[curr].top(), mp, dp, visited));
//             }
//             // cout << curr << " " << mp[curr].top() << endl;
//             // cout << curr << " " << mp[curr].top() << endl;
//             visited.insert({curr, mp[curr].top()});
//             // mp[curr].pop();
//             // auto temp = mp[curr].top();
//             // mp[curr].pop();
//             // res = max(res, bt(i, people, temp, mp));
//         }
//     }
//     // cout << res << endl;
//     return dp[i][curr];
// }

// int main() {
//     set<pair<int, int>> visited;
//     int n, m;
//     cin >> n >> m;
//     vector<vector<int>> dp(m, vector<int>(n+1, -1));
//     unordered_map<int, priority_queue<int, vector<int>, greater<int>>> mp;
//     for(int i = 1; i < n; i++) {
//         int a, b;
//         cin >> a >> b;
//         mp[a].push(b);
//     }
//     vector<int> people;
//     for(int i = 0; i < m; i++) {
//         int d;
//         cin >> d;
//         people.push_back(d);
//     }
//     // for(auto i : people) {
//     //     cout << i << " ";
//     // }
//     // cout << endl;
//     cout << bt(0, people, 1, mp, dp, visited);
// }