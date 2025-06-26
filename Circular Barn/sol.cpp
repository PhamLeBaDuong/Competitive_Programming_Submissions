#include <climits>
#include <cstdio>
#include <math.h>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }
    int res = INT_MAX;
    for(int i = 0; i < n; i++) {
        int tempres = 0;
        for(int j = 0; j < n; j++) {
            tempres += nums[j]*((j-i) < 0 ? (j-i+n) : (j-i));
        }
        res = min(res, tempres);
    }
    cout << res << endl;
}