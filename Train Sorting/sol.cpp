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
    cin >> n;
    vector<int> nums(n);
    for(int i = 0; i < n; i++) {
        cin >> nums[i];
    }
    vector<int> lds(n, 1);
    for(int i = 1; i < n; ++i) {
        for(int j = 0; j < i; ++j) {
            if(nums[i] < nums[j] && lds[i] < lds[j] + 1) {
                lds[i] = lds[j] + 1;
            }
        }
    }
    vector<int> lis(n, 1);
    for(int i = n-2; i >= 0; --i) {
        for(int j = n-1; j > i; --j) {
            if(nums[i] < nums[j] && lis[i] < lis[j] + 1) {
                lis[i] = lis[j] + 1;
            }
        }
    }
    int maxLen = 0;
    for(int i = 0; i < n; ++i) {
        maxLen = max(maxLen, lis[i] + lds[i] - 1);
    }
    cout << maxLen;
    return 0;
}
    