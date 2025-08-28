#include <math.h>
#include <iostream>
#include <unordered_set>
#include <utility>
#include <vector>
#include <unordered_map>
using namespace std;
int main() {
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        unordered_map<int, int> count;
        bool res = false;
        while(n--) {
            int x;
            cin >> x;
            count[x]++;
            if(count[x] >= 2) {
                res = true;
            }
        }
        if(res) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }
}