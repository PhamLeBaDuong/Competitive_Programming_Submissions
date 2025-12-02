#include <math.h>
#include <iostream>
#include <unordered_set>
#include <utility>
#include <vector>
#include <unordered_map>
using namespace std;
typedef long long int lli;
int main() {
    lli n, p;
    cin >> n >> p;
    n++;
    lli temp = 1;
    lli count = 1;
    auto org_n = n;
    while(n > 0) {
        temp = n%p == 0 ? p : n%p;
        count *= temp;
        // if(n < p && (n+p-1)/p == 1) {
        //     break;
        // }
        n = (n+p-1)/p;
    }
    cout << org_n - count << endl;
}