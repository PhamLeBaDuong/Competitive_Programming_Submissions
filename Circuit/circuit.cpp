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
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int count0 = 0;
        int count1 = 0;
        for(int i = 0; i < 2*n; i++) {
            int temp;
            cin >> temp;
            if(temp == 0) {
                count0++;
            }
            else {
                count1++;
            }
        }
        cout << count0%2 << " " << min(count1, count0) << endl;
    }
}