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
        int n, m, k;
        cin >> n >> m >> k;
        string s;
        cin >> s;
        int count0 = 0;
        int res = 0;
        int kk = 0;
        for(auto i : s) {
            if(i == '0' ) {
                if(kk > 0) {
                    kk--;
                }
                else {
                    count0++;
                    if(count0 == m) {
                        count0 = 0;
                        kk = k-1;
                        res++;
                    }
                }
            }
            else {
                count0 = 0;
                if(kk > 0){
                    kk--;
                }

            }
        }
        cout << res << endl;
    //     vector<int> arr;
    //     vector<vector<int>> range;
    //     int temp = 0;
    //     int temp1 = 0;
    //     for(int i = 0; i < s.size(); i++) {
    //         if(s[i] == '0') {
    //             if(temp == 0) {
    //                 temp1 = i;
    //             }
    //             temp++;
    //         }
    //         else if(temp != 0) {
    //             arr.push_back(temp);
    //             range.push_back({temp1, i-1});
    //             temp = 0;
    //         }
    //     }
    //     int nn = s.size();
    //     if(temp != 0) {
    //         arr.push_back(temp);
    //         range.push_back({temp1, nn-1});
    //     }
    //     long long res = 0;
    //     for(int i = 0; i < arr.size(); i++)
    //     {
    //         res += ceil((double)(arr[i])/(m-1+k)) - (arr[i]%(m-1+k) > 0 && arr[i]%(m-1+k) <= (m-1) ? 1 : 0);
    //         long long outbits = arr[i]%(m-1+k) <= (m-1) ? 0 : k-(arr[i]%(m-1+k) - (m-1));
    //         // if(i < arr.size()-1) {
    //         // }
    //         int ii = i;
    //         while(ii < arr.size()-2 && arr[ii+1] - (outbits-(range[ii+1][0] - range[ii][1]-1)) <= 0 && outbits > 0) {
    //             outbits -= arr[ii+1]+(range[ii+2][1] - range[ii+1][0]-1);
    //             arr[ii+1] = 0;
    //             ii++;
    //         }
    //         // if(ii < arr.size()-1) {
    //             arr[ii] -= outbits-(range[ii+1][0] - range[ii][1]-1);
    //         // }
    //     }
    //     cout << res << endl;
    // }
    }
}