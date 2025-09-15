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
        cin >> n;
        vector<int> a(n);
        for(int i = 0; i < n; i++) {
            cin >> a[i];
        }
        unordered_map<int, int> count;
        int flag = 0;
        for(int i = 0; i < n; i++) {
            bool flagg = count[a[i]] != 0 && count[a[i]] % a[i] == 0;
            count[a[i]]++;
            if(count[a[i]] % a[i] != 0) {
                if(flagg) {
                    flag--;
                }
            }
            else {
                if(!flagg) {
                    flag++;
                }
            }
        }
        if(flag == count.size()) {
            int curr = 1;
            unordered_map<int, int> c;
            unordered_map<int, int> mp;
            for(int i = 0; i < n; i++) {
                c[a[i]]++;
                if(a[i] == 1 || c[a[i]] % a[i] == 1) {
                // if(c[a[i]] == 1 || c[a[i]] % a[i] == 1) {
                    mp[a[i]] = curr;
                    curr++;
                }
                cout << mp[a[i]] << " ";
            }
            cout << endl;
        }
        else {
            cout << "-1" << endl;
        }
    }
}