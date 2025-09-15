#include <math.h>
#include <iostream>
#include <unordered_set>
#include <utility>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <queue>
using namespace std;
typedef long long int lli;
int main() {
    int t;
    cin >> t;
    while(t--) {
        int n, k;
        cin >> n >> k;
        vector<int> a(n);
        unordered_map<int, int> count;
        lli minn = INT_MAX;
        lli maxx = INT_MAX;
        for(int i = 0; i < n; i++) {
            cin >> a[i];
            count[a[i]]++;
            if(count[a[i]] > 1) {
                minn = min(minn, (lli)a[i]);
            }
        }
        int mex = 0;
        sort(a.begin(), a.end());
        for(int i = 0; i < n; i++) { 
            if(a[i] == mex) {
                mex++;
            }
            else if(a[i] > mex) {
                break;
            }
        }
        lli res = 0;
        for(auto &i : a) {
            if(i > mex || count[i] > 1) {
                res += mex;
            }
            else {
                maxx = max(maxx, (lli)i);
                res += i;
            }
        }
        cout << minn << " " << res << " " << mex << endl;
        if(k > 1) {
            if (minn == -1 || minn > mex) {
                minn = mex;
            }
            if(mex == n-1) {
                cout << res << endl;
                cout << endl;
                continue;
            }
            cout << (minn*(minn-1))/2+(n - minn)*(k&1 ? minn : minn+1) << endl;
        }
        else {
            cout << res << endl;
        }
        cout << endl;
    }
}
// 6 6 4 2 3 0 1 8
// 0 1 2 3 4 6 6 8
// 0 1 2 3 4 5 5 5
// 0 1 2 3 4 6 6 6

// 0 1 2 3 4 5 5 5 6 7
// 0 1 2 3 4 8 8 8 6 7

// 0 1 2 3 3 3 4 5 6 6 7 8
// 0 1 2 9 9 9 4 5 9 9 7 8
// 0 1 2 3 3 3 3 3 3 3 3 3

// 0 2 3
// 0 1 1
// 0 2 2

// 0 1 3 5
// 0 1 2 2

// 