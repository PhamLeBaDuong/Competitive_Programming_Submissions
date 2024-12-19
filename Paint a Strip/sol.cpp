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
    while(t--)  {
        int n;
        cin >> n;
        int x = 4;
        int res = 2;
        if(n == 1) {
            res = 1;
        }
        else if(n > 4) {
            while(x < n) {
                x += x+2;
                res++;
            }
        }
        cout << res << endl << endl;
    }
}