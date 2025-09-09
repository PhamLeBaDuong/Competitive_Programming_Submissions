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
    int t;
    cin >> t;
    while(t--) {
        long long int a, b;
        cin >> a >> b;
        if(a & 1) {
            if(b & 1) {
                cout << a*b + 1 << endl;
            }
            else {
                if((b/2)&1) {
                    cout << "-1" << endl;
                }
                else {
                    cout << a*(b/2) + 2 << endl;
                }
            }
        }
        else {
            if(b & 1) {
                cout << "-1" << endl;
            }
            else {
                cout << max(a + b, a*(b/2) + 2) << endl;
            }
        }
    }
}