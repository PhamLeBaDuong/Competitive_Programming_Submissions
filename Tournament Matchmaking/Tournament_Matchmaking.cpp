#include <math.h>
#include <utility>
#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;

int main() {
    unordered_map<int, vector<unordered_set<int>>> mp;
    int n;
    cin >> n;
    for(int ii = 0; ii < n; ii++) {
        int nn;
        cin >> nn;
        unordered_set<int> temp;
        for(int i = 0; i < nn; i++) {
            int firstRole;
            int secondRole;
            cin >> firstRole;
            cin >> secondRole;
            temp.insert(firstRole);
            temp.insert(secondRole);
        }
        mp[nn].push_back(temp);
    }
    int res = 0;
    for(int i = 1; i <= 7; i++) {
        if(mp.find(i) != mp.end() && mp.find(15-i) != mp.end()) {
            for(auto ii : mp[i]) {
                for(auto j : mp[15-i]) {
                    bool valid = true;
                    for(int t = 1; t <= 15; t++) {
                        if(ii.find(t) == ii.end() && j.find(t) == j.end()) {
                            valid = false;
                            break;
                        }
                    }
                    if(valid) {
                        res++;
                    }
                }
            }
        }
    }
    cout << res;
}