#include <math.h>
#include <iostream>
#include <string>
#include <utility>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <queue>
#include <bits/stdc++.h>
#include <unordered_set>
using namespace std;
int main() {
    int t;
    cin >> t;
    while(t--)  {
        int n, x, y;
        cin >> n >> x >> y;
        vector<int> a(n);
        for(int i = 0; i < n; i++) {
            a[i] = i%2;
        }
        a[n-1] = (n&1 ? 2 : 1);
        if(a[x-1] == a[y-1]) {
            if(n&1) {
            a[y-1]=2;
                for(int i = y; i < n; i++) {
                    a[i] = i&1 ? 0 : 1;
                }
            }
            else {
                if(n == 4) {
                    a[x-1] = 2;
                    a[x%n] = 1;
                    a[(x+1)%n] = 0;
                    a[(x+2)%n] = 1;

                }

            a[y-1]=2;
                if(a[x-1] == 0) {
                    a[y%n] = 0;
                    a[(y+1)%n] = 1;
                    a[(y+2)%n] = 2;
                }
                else {
                    a[y%n] = 1;
                    a[(y+1)%n] = 0;
                    a[(y+2)%n] = 2;
                    if(a[(y+3)%n] == 2) {
                        a[(y+2)%n] = 1;
                    }
                }

            }
        }
        for(auto i : a) {
            cout << i << " ";
        }
        cout << endl;
    }
}
// 0 1 0 2 1 0 2 1
// 0 1 2 0 1 2 0 1
// 0 1 0 1 2 1 0 1 2
// 0 1 0 2 1 0 1 0 1 
// 0 2 0 1
