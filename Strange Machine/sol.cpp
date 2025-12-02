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
    int t;
    cin >> t;
    while( t-- ) {
        int n, q;
        cin >> n >> q;
        string s;
        cin >> s;
        vector<int> pre(n, 0);
        int mult = 0;
        int add = 0;
        for(int i = 0; i < n; i++) {
            if(s[i] == 'A') {
                add++;
            }
            else {
                mult++;
                add*=2;
            }
            pre[i] = add*(pow(2, mult));
            pre[i] = (pre[i] == 0 ? 1 : pre[i]);
            // pre[i] = max(1, add)*(pow(2, mult));
            cout << pre[i] << " ";
        }
        cout << endl;
        vector<int> res;
        while(q--) {
            int count = 0;
            int query;
            cin >> query;
            // int i = 0;
            // while(query != 0) {
            //     if(s[i] == 'A') {
            //         query--;
            //     }
            //     else {
            //         query /= 2;
            //     }
            //     i = (i+1)%n;
            //     count++;
            // }
            while((query-add)/pow(2, mult)>0) {
                query = (query-add)/pow(2, mult);
                count += n;
            }
            int temp = -1;
            int l = 0;
            int r = n-1;
            while(l <= r) {
                int m = (l+r)/2;
                if(pre[m] <= query) {
                    temp = m;
                    l = m+1;
                }
                else {
                    r = m-1;
                }
            }
            count += temp+1;
            res.push_back(count);
        }
        cout << endl;
        for(int i = 0; i < res.size(); i++) {
            cout << res[i] << endl;
        }
        cout << endl;
    }
}