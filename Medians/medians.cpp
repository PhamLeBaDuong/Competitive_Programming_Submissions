#include <math.h>
#include <iostream>
#include <string>
#include <utility>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <queue>
using namespace std;
int main()  {
    int t;
    cin >> t;
    while (t--) {
        int n , k;
        cin >> n >> k;
        if(n == 1) {
            cout << 1 << endl;
            cout << 1 << endl;
        }
        else {
            if(k > 1 && k < n) {
                if((n-k)&1) {
                    cout << 3 << endl;
                    cout << 1 << " " << k << " " << k+1 << endl;
                }
                else {
                    cout << 3 << endl;
                    cout << 1 << " " << k-1 << " " << k+2 << endl;
                }
            }
            else {
                cout << -1 << endl;
            }
        }
    }
}