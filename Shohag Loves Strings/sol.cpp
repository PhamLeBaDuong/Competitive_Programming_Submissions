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
    while(t--) {
        string s;
        cin >> s;
        int i = 1;
        int j = 0;
        vector<int> res(s.size());
        while(i < s.size()) {
            if(s[j] == s[i]) {
                res[i] = j+1;
                i++;
                j++;
            }
            else if(j == 0) {
                res[i] = 0;
                i++;
            }
            else {
                j = res[j-1];
            }
        }
        for(int i = 0; i < s.size(); i++) {
            cout << res[i] << " ";
        }
    }
}