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
        int n;
        cin >> n;
        int minSub = INT_MAX;
        int minSum = INT_MAX;
        while(n--) {
            int x, y;
            cin >> x >> y;
            minSub = min(minSub, x - y);
            minSum = min(minSum, x + y);
        }
        long long int v = 1000000000;
        long long int temp = 0;
        long long int summ = 0;
        long long int subb = 0;
        cout << "? L " << v << endl;
        cout.flush();
        cin >> temp;
        cout << "? L " << v << endl;
        cout.flush();
        cin >> temp;
        cout << "? U " << v << endl;
        cout.flush();
        cin >> temp;
        cout << "? U " << v << endl;
        cout.flush();
        cin >> temp;
        subb = temp - minSub - 4*v;
        cout << "? D " << v << endl;
        cout.flush();
        cin >> temp;
        cout << "? D " << v << endl;
        cout.flush();
        cin >> temp;
        cout << "? D " << v << endl;
        cout.flush();
        cin >> temp;
        cout << "? D " << v << endl;
        cout.flush();
        cin >> temp;
        summ = (temp - minSum - 4*v) * (-1);
        cout << "! " << summ - ((summ + subb)/2) << " " << (summ + subb)/2 << endl;
    }
}