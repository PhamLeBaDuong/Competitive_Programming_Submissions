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
        int n, k;
        cin >> n >> k;
        vector<int> arr(n);
        for(int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        int result = -1;
        for(int i = 0; i < n; i++) {
            if(result != -1) {
                break;
            }
            result = i;
            bool tempres = true;
            for(int j = 0; j < n; j++) {
                if(j == i) {
                    continue;
                }
                if(abs(arr[i] - arr[j]) % k != 0) {
                    result = i;
                }
                else {
                    tempres = false;
                    result = -1;
                    break;
                }
            }
        }
        if(result != -1) {
            cout << "YES" << endl << result+1 << endl;
        } else {
            cout << "NO" << endl;
        }
        // cout << endl;

    }
}