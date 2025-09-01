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
    while (t--) {
        int n, k;
        cin >> n >> k;
        string s;
        cin >> s;
        vector<int> ans(n);
        int count1 = 0;
        int count = 0;
        bool flag = false;
        for(auto &i : s) {
            if(i == '1') {
                count1++;
                count++;
                if(count >= k) {
                    cout << "NO" << endl;
                    flag = true;
                    break;
                }
            }
            else {
                count = 0;
            }
        }
        if(flag) {
            continue;
        }
        int a = count1;
        int b = 0;
        cout << "YES" << endl;
        for(int i = 0; i < n; i++) {
            if(s[i] == '0') {
                cout << a+1 <<  " ";
                a++;
            }
            else {
                cout << b+1 << " ";
                b++;
            }
        }
        cout << endl;
    }

}