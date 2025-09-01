
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
    while (t--) {
        int a,b,c,d;
        cin >> a >> b >> c >> d;
        if(a > (b+1) * 2 || b > (a+1) * 2) {
            cout << "NO" << endl;
            continue;  
        }
        c = c-a;
        d = d-b;
        if(c > (d+1) * 2 || d > (c+1) * 2) {
            cout << "NO" << endl;
            continue;  
        }
        cout << "YES" << endl;
    }
}