#include <math.h>
#include <iostream>
#include <unordered_set>
#include <utility>
#include <vector>
#include <unordered_map>
using namespace std;
int main() {
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        cout << (n <= 3 ? 1 : (n-2)/2 + (n&1)) << endl;
    }
}


// 500
// 2*2*5*5*5