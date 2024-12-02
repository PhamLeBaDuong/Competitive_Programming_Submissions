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
    vector<int> arr;
    unordered_map<int, int> mp;
    while(true) {
        int a, b;
        cin >> a >> b;
        if(a == 0 && b == 0) {
            break;
        }
        arr.push_back(a);
        mp[b]++;
    }
    int res = 0;
    for(auto i : arr) {
        res += i*mp[i];
    }
    cout << res << endl;
}