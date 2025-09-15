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
        int n;
        string s;
        cin >> n >> s;
        int count = 0;
        int temp = -1;
        for(int i = s.size()-1; i >= 0; i--) {
            if(s[i] == '1') {
                count++;
                // temp = i;
            }
        }
        int res = 0;
        for(int i = n - count - 1; i >= 0; i--) {
            if(s[i] == '1') {
                res++;
            }
        }
        // cout << n - temp - count << endl;
        cout << res << endl;
        // cout << endl;
    }
}