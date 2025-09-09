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
int main() {
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for(int i = 0; i < n; i++) {
            cin >> a[i];
        }
        // vector<int> aa(3);
        // aa[2] = 3;
        if(n == 2) {
            cout << (a[0] == 1 ? "2 1" : "1 2") << endl;
            continue;
        }
        vector<int> res;
        for(int i = 0; i < n; i++) {
            // res.push_back(3 - a[i] % 3 + aa[2 - a[i]%3]);
            // aa[2 - a[i]%3] += 3;
            // cout << res[i] << " ";
            cout << (n - a[i] == 0 ? n : n - a[i]) << " ";
        }
        cout << endl;

    }
}