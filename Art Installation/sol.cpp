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
    int r, g, b, cr, cg, cb, crg, cgb;
    cin >> r >> g >> b >> cr >> cg >> cb >> crg >> cgb;
    int neededR = max(0, r - cr);
    int neededB = max(0, b - cb);
    int neededG = max(0, g - cg);

    // int neededRG = neededR;
    // int neededGB = neededB;
    if(neededR > crg || neededB > cgb || neededR + neededB + neededG > crg + cgb) {
        cout << -1 << endl;
        return 0;
    }
    cout << neededR + neededB + neededG << endl;
    return 0;
    int res = 0;
    int spareRG = crg - neededR; 
    if(spareRG < 0) {
        res -= spareRG;
        spareRG = 0;
    }
    int spareGB = cgb - neededG;
    if(spareGB < 0) {
        res -= spareGB;
        spareGB = 0;
    }
    res += max(0, neededG - spareGB - spareRG);
    cout << res << endl;
    
}