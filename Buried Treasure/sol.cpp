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
    int n, m;
    cin >> n >> m;
    vector<vector<bool>> aa(2*m+2, vector<bool>(2*m+2, false));
    vector<vector<bool>> ap(2*m+2, vector<bool>(2*m+2, false));
    vector<bool> ip(2*m + 2, true);
    // vector<vector<bool>> aa(2, vector<bool>(m));
    bool res = true;
    for(int i = 0; i < n; i++) {
        int m1, m2;
        cin >> m1 >> m2;
        if(abs(m1) > abs(m2)) {
            auto temp = m1;
            m1 = m2;
            m2 = temp;
        }
        // int a = m1 > 0 ? 0 : 1;
        // int b = m2 > 0 ? 0 : 1;
        int pim1 = m1 < 0 ? -m1 + m : m1;
        int im1 = m1 < 0 ? -m1 : m1 + m;
        
        int pim2 = m2 < 0 ? -m2 + m : m2;
        int im2 = m2 < 0 ? -m2 : m2 + m;

        aa[im1][im2] = true;
        
        if(aa[im1][im2] && aa[im1][pim2]) {
            if(!ip[im1]) {
                res = false;
            }
            ip[pim1] = false;
        }

        if(aa[im1][im2] && aa[pim1][im2]) {
            if(!ip[im2]) {
                res = false;
            }
            ip[pim2] = false;
        }

        // if(aa[im1][pim2] && aa[pim1][im2] && aa[pim1][pim2]) {
        // // if(aa[m1 < 0 ? -m1 + m : m1][m2 < 0 ? -m2 + m : m2] == true ) {
        //     res = false;
        // }
        // cout << im1 << " " << im2 << " " << pim1 << " " << pim2 << endl << endl;
        // cout << "bruh" << endl;
    }
    if(res) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }
}
// 1 2
// -1 2
// -1 -2

// 3 -2
// -3 -2
// -3 2

// 1 2
// -1 2
// 