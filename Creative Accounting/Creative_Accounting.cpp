#include <math.h>
#include <utility>
#include <vector>
#include <iostream>
using namespace std;

int main() {
    // std::ios_base::sync_with_stdio(false);
    // std::cin.tie(NULL);
    int n, l, h;
    cin >> n >> l >> h;
    vector<int> arr(n);
    for(int i = 0; i < n; i++) {
        int p;
        cin >> p;
        // cout << p << " ";
        arr[i] = p;
    }
    // cout << 0;
    int resMax = -1;
    int resMin = 100000;

    vector<int> prefSum(arr.size()+1, 0);
    for(int i = 1; i <= arr.size(); i++) {
        prefSum[i] = prefSum[i-1] + arr[i-1];
    }

    for(int i = l; i <= h; i++) {
        for(int j = 1; j <= i; j++) {
            int count = 0;
            for(int t = j; t < prefSum.size(); t += i) {
                // cout << i << " " << j << " " << t << endl;
                count += (prefSum[t] - prefSum[max(0,t-i)]) > 0 ? 1 : 0;
            }
            count += (prefSum[prefSum.size()-1] - prefSum[prefSum.size() - 1 - (((prefSum.size()-1-j)%i))]) > 0 ? 1 : 0;
            resMax = max(resMax, count);
            resMin = min(resMin, count);
            // cout << count << " ";
        }
        // cout << endl;
    }
    cout << resMin << " " << resMax;
}