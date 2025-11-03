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
    vector<int> arr(n);
    cin >> n;
    for(auto &i : arr) {
        cin >> i;
    }
    int m;
    vector<vector<int>> mp(n, vector<int>(n, 0));
    cin >> m;
    for(int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        mp[a][b] = c;
        mp[b][a] = c;
    }
    
}