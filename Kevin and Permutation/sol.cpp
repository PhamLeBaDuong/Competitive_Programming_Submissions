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
        vector<int> arr(n,0);
        int curr = 1;
        for(int i = k-1; i < n; i+=k) {
            arr[i] = curr;
            curr++;
        }
        for(int i = 0; i < n; i++) {
            if(arr[i] == 0) {
                cout << curr << " ";
                curr++;
            }
            else {
                cout << arr[i] << " ";
            }
        }
        cout << endl;

    }
}
// 6 4 2 1 3 5 7
// 4 2 1 1 3 5
// 1 2 3 4 5 6 7
// 1 2 3 4 5 6

// 4 6 2 8 3 1 5 7
// 2 2 2 1 1 1
// 8 6 4 2 1 3 5 7
// 4 2 1 1 1 3
// 3 4 1 5 6 2 7 8
// 1 1 1 