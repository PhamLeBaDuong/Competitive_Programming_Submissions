#include <math.h>
#include <iostream>
#include <string>
#include <utility>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <queue>
using namespace std;
int main() {
	// freopen("mixmilk.in", "r", stdin);
    // int c1, m1, c2, m2, c3, m3;
    vector<int> c(3);
    vector<int> m(3);
    cin >> c[0] >> m[0] >> c[1] >> m[1] >> c[2] >> m[2];
    for(int i = 0; i < 100; i++) {
        int curr = i%3;
        if(curr < 2) {
            auto temp = m[curr] + m[curr+1];
            m[curr+1] = min(c[curr+1], temp);
            m[curr] = temp-m[curr+1];
        }
        else {
            auto temp = m[curr] + m[0];
            m[0] = min(c[0], temp);
            m[curr] = temp%c[0];
        }
    }
    cout << m[0] << endl << m[1] << endl << m[2];
	// freopen("mixmilk.out", "w", stdout);
}