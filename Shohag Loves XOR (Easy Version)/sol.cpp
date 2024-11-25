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
        long long x, m;
        cin >> x >> m;
        long long res = 0;
        long long cond = min(2*x, m);
        for (long long i = 1; i <= cond; i++) {
            if(x == i) {
                continue;
            }
            long long temp = x ^ i;
            if (x % temp == 0 || i % temp == 0) {
                res++;
            }
        }
        cout << res << endl;
    }
}