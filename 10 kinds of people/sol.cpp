#include <math.h>
#include <iostream>
#include <unordered_set>
#include <utility>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <queue>
using namespace std;

long long int cal(vector<int> &val, int base) {
    long long int res = 0;
    for(int i = 0; i < val.size(); i++) {
        res += val[i] * pow(base, val.size() - 1 - i);
    }
    return res;

}

int main() {
    int t;
    cin >> t;
    while(t--) {
        string A, B;
        cin >> A >> B;
        vector<int> val_A;
        vector<int> val_B;
        int max_A = 1;
        int max_B = 1;
        for(auto &ch : A) {
            if(isdigit(ch)) {
                val_A.push_back(ch - '0');
            }
            else {
                if(islower(ch)) {
                    val_A.push_back(ch - 'a' + 10);
                }
                else {
                    val_A.push_back(ch - 'A' + 36);
                }
            }
            max_A = max(max_A, val_A.back());
            // cout << val_A.back() << " ";
        }
        // cout << "\n";

        for(auto &ch : B) {
            if(isdigit(ch)) {
                val_B.push_back(ch - '0');
            }
            else {
                if(islower(ch)) {
                    val_B.push_back(ch - 'a' + 10);
                }
                else {
                    val_B.push_back(ch - 'A' + 36);
                }
            }
            max_B = max(max_B, val_B.back());
            // cout << val_B.back() << " ";
        }
        // cout << "\n";
        bool flag = false;
        // for(int i = 7500; i >= 2; i--) {
        unordered_map<int, long long int> map_B;
        for(int i = max_A+1; i <= 7500; i++) {
            long long int target = cal(val_A, i);
            int l = max_B+1;
            int h = 7500;
            int temp_res = -1;
            long long int target_B = -1;
            while(l <= h) {
                int m = (l + h) / 2;
                long long int val;
                if(map_B.find(m) != map_B.end()) {
                    val = map_B[m];
                }
                else {
                    val = cal(val_B, m);
                    map_B[m] = val;
                }
                if(val <= target) {
                    temp_res = m;
                    target_B = val;
                    l = m + 1;
                }
                else {
                    h = m - 1;
                }
            }
            if(target_B == target) {
                cout << target << " " << i << " " << temp_res << "\n";
                flag = true;
                break;
            }
        }
        if(!flag) {
            cout << "CANNOT MAKE EQUAL\n";
        }
    }
}

/*
1 61
1 2 3

5 + 61

49 + 14 + 3
*/