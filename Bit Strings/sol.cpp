#include <math.h>
#include <iostream>
#include <string>
#include <utility>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <queue>
using namespace std;
int main() {
    int n;
    cin >> n;
    int res = 1;
    while(n--) {
        res = (res*2)%1000000007;
    }
    cout << res << endl;
    return 0;
}