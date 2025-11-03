#include <math.h>
#include <iostream>
#include <unordered_set>
#include <utility>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <queue>
using namespace std;

int bt() {
    
}

int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        vector<int> arr(n);
        int sum = 0;
        for(int i = 0; i < n; i++) {
            cin >> arr[i];
            sum += arr[i];
            // sum %= 3;
        }
        // if(sum == 0) {
        //     sum = 3;
        // }
        vector<int> pre(n);
        // vector<int> suf(n);
        // for(int i = 0; i < n; i++) {
        //     pre[i] = arr[i];
        //     if(i > 0) {
        //         pre[i] = min(pre[i], pre[i-1] + 1);
        //     }
        // }
        // for(int i = n-1; i >= 0; i--) {
        //     suf[i] = arr[i];
        //     if(i < n-1) {
        //         suf[i] = min(suf[i], suf[i+1] + 1);
        //     }
        // }
        vector<int> a(4,-1);
        pre[0] = arr[0];
        int prev = arr[0];
        bool flag = false;
        a[prev%3] = 0;
        // int temp = arr[0] % 3;
        for(int i = 1; i < n; i++) {
            int curr = (arr[i] + prev);
            // curr = curr == 0 ? 3 : curr;
            for(int j = 0; j < 3; j++) {
                if(a[j] != -1) {
                    if((abs(sum - curr)%3 == abs(curr - pre[a[j]])%3 == pre[a[j]]%3) || (abs(sum - curr)%3 != abs(curr - pre[a[j]])%3 != pre[a[j]]%3)) {
                        flag = true;
                        // cout << sum -curr << " " << curr - pre[a[j]] << " " << pre[a[j]] << endl;
                        cout << a[j]+1 << " " << i+1 << endl;
                        break;
                    }
                }
            }
            a[curr%3] = i;
            pre[i] = pre[i-1] + arr[i];
            prev = curr;
            if(flag) {
                break;
            }
        }
        cout << endl;
    }
}