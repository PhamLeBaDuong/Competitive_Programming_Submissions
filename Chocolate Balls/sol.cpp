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
    int n, a, b;
    cin >> n;
    cin >> a >> b;
    int sum = a + b;

    int aver = sum / n;
    int target = sum / n;
    int res = 0;
    if(a <= aver) {
        res += aver - a;
    }
    else {
        res += a - aver - 1;
    }
    if(b <= aver) {
        res += aver - b;
    }
    else {
        res += b - aver - 1;
    }
    // int res =  aver+1-a + aver+1-b;
    // for(auto &i : arr) {
    //     if(i < target) {
    //         res += target-i;
    //     }
    // }

    cout << res << endl;
}