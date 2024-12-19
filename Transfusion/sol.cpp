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
int main() {
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        vector<int> arr(n);
        int minn = INT_MAX;
        int maxx = INT_MIN;
        for(int i = 0; i < n; i++) {
            cin >> arr[i];
            minn = min(minn, arr[i]);
            maxx = max(maxx, arr[i]);
        }
        bool res = false;
        int st = minn + (maxx-minn) / 4;
        int en = minn + ((maxx - minn) / 4) * 3;
        for(int i = st; i <= en; i++) {
            vector<int> count(2);
            int countt = 0;
            for(int j = 0; j < n; j++) {
                count[j%2] += i - arr[j];
                countt += i - arr[j];
            }
            if(count[0] == 0 && count[1] == 0 && countt == 0) {
                cout << "YES" << endl;
                res = true;
                break;
            }
        }
        if(!res) {
            cout << "NO" << endl;
        }
    }
}