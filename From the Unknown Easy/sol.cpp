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
        int maxx = 100000;
        cout << "? " << maxx << " ";
        for(int i = 0; i < maxx; i++) {
            cout << 1 << " ";
        }
        cout.flush();
        int a;
        cin >> a;
        int st = maxx/a;
        int en = (maxx-1)/(a-1);
        int temp = (en - st + 1);
        cout << "? " << temp * 2 << " " ;
        // cout << "? " << temp + (temp * (temp + 1)) / 2 << " " ;
        for(int i = 0; i <= en - st; i++) {
            // cout << maxx << " ";
            cout << maxx << " " << i << " ";
            // for(int j = 0; j < i; j++) {
            //     cout << 1 << " ";
            // }
        }
        cout.flush();
        int b;
        cin >> b;
        cout << "! " << en - (b - temp + 1) << endl;
        cout.flush();

        // if(maxx % a == 0) {
        //     cout << "! " << maxx/a << endl;
        // }
        // else {
        //     for(int i = 1; i <= maxx; i++) {
        //         auto temp = maxx - (a - 1) * i;
        //         if(maxx / i + (maxx % i == 0 ? 0 : 1) == a){      
        //             cout << "! " << i << endl;
        //             break;
        //         }
        //     }
        // }
    }
}
// (x-1)* W + ? = m
// m / W + (m%W == 0 ? 0 : 1) == x
// m / x + W / x == W
// W ( x - 1 ) + 1 == m
// m/x -> (m-1)/(x-1)