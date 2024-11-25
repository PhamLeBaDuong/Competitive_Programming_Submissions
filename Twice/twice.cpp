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
        vector<int> arr(n+1);
        while(n--) {
            int a;
            cin >> a;
            arr[a]++;
        }
        int res = 0;
        for(auto i : arr) {
            res += i/2;
        }
        cout << res << endl;
    }
}