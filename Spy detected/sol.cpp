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
int main() {

    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        int res1 = -1;
        int v1 = -1;
        int res2 = -1;
        int v2 = -1;
        int sum = 0;
        for(int i = 0; i < n; i++) {
            int a;
            cin >> a;
            sum += a;
            if(res1 == -1) {
                if(res2 == -1 || a == v2) {
                    res2 = i+1;
                    v2 = a;
                }
                else {
                    res1 = i+1;
                    v1 = a;
                }
            }
        }
        if((sum - v1) / v2 == n-1) {
            cout << res1 << endl;
        }
        else {
            cout << res2 << endl;
        }
    }
}