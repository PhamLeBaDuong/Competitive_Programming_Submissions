#include <math.h>
#include <iostream>
#include <unordered_set>
#include <utility>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <queue>
using namespace std;
int main() {
    int t;
    cin >> t;
    while(t--) {
        long long int x;
        cin >> x;
        cout << 8*x << endl;
        // for(int i = 1; i*i <= x; i++) {
        //     if(pow(10,log10(i)+1))
        //     if(x%i == 0) {
        //         cout << x/i << endl;
        //         break;
        //     }
        // }

    }
}
// (x*10^a + y) % (x + y)
// 2*3*7 3*2*2 -> 2*2*3*3*3*13