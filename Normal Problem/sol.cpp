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
        string a;
        cin >> a;
        string res = "";
        for(int i = a.size()-1; i >= 0; i--) {
            if(a[i] == 'p') {
                res.push_back('q');
            }
            else if(a[i] == 'q') {
                res.push_back('p');
            }
            else {
                res.push_back(a[i]);
            }
        }
        cout << res << endl;
    }
}