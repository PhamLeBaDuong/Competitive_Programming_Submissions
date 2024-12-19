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
void bt() {
    if(i > arr.size()) {
        return;
    }
    if(arr[i] < maxx(-1) {
        return;
    }
    if(arr[i] == maxx) {
        bt();
        bt();
    }
    else if(arr[i] == maxx-1) {
        bt();
    }
}
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
    }
}
// 1 1 2 2 1 1 3 3 1 1
// 1 0 2 2 1
// 1 0 2 0 1 0
// 1 0 2 0 1 1
// 1 8 2 2 1 3 3 9 1 1