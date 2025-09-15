#include <math.h>
#include <iostream>
#include <unordered_set>
#include <utility>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <queue>
#include <cmath>
#define _USE_MATH_DEFINES
using namespace std;
typedef long long int lli;
int main() {
    int n, y;
    int count = 0;
    cin >> n >> y;
    unordered_set<int> st;
    for(int i = 0; i < y; i++) {
        int a;
        cin >> a;
        st.insert(a);
    }
    for(int i = 0; i < n; i++) {
        if(st.find(i) == st.end()) {
            cout << i << endl;
        }
    }
    cout << "Mario got " << st.size() << " of the dangerous obstacles." << endl;
}