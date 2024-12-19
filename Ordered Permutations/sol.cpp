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
void bt(int curr, int &n, long long int &k, int st, int en, vector<int> &arr, long long int &count) {
    if(curr == n) {
        arr[st] = curr;
        count++;
        return;
    }
    arr[st] = curr;
    bt(curr+1, n, k, st+1, en, arr, count);
    if(count >= k) {
        return;
    }
    arr[st] = 0;
    arr[en] = curr;
    bt(curr+1, n, k, st, en-1, arr, count);
    if(count >= k) {
        return;
    }
    arr[en] = 0;
}
int main() {
    int t;
    cin >> t;
    while(t--) {
        int n;
        long long int k;
        cin >> n >> k;
        if((n == 1 ? 1 : pow(2, n-1)+1) < k) {
            cout << -1 << endl;
            continue;
        }
        int numMax = pow(2, n-1)+1;
        vector<int> arr(n+1, 0);
        int st = 1;
        int en = n;
        for(int i = 1; i <= n; i++) {
            if(k > numMax/2) {
                arr[i] = en;
                en--;
                numMax /= 2;
                k -= numMax/2;
            }
            else {
                arr[i] = st;
                st++;
            }
        }
        // long long int count = 0;
        // bt(1, n, k, 1, n, arr, count);
        for(int i = 1; i <= n; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
}