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
        int m, a, b, c;
        cin >> m >> a >> b >> c;
        cout << min(a, m) + min(b, m) + min(c, m+m- min(a, m) - min(b, m)) << endl;
    }
}