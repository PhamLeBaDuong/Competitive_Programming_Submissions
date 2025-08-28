#include <math.h>
#include <iostream>
#include <unordered_set>
#include <utility>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;
int main() {
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        vector<int> arr(n);
        for(int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        sort(arr.begin(), arr.end(), greater<int>());
        long long int res = 0;
        for(int i = 0; i < n; i += 2) {
            res += arr[i];
        }
        cout << res << endl;
    }
}