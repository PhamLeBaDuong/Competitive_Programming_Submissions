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
        bool flag = false;
        long long x;
        cin >> x;
        while(x%33 != 0) {
            long long temp = x;
            long long count = 10;
            long long top = temp%100;
            temp /= 100;
            while(temp) {
                // cout << top << endl;
                if(top / (count/10) == 33) {
                    flag = true;
                    temp *= count/10;
                    temp += top % (count/10);
                    break;
                }
                top = (temp%10)*(count*10) + top;
                temp /= 10;
                count *= 10;
            }
            if(flag) {
                flag = false;
                x=temp;
            }
            else {
                flag = true;
                break;
            }
        }
        if(flag) {
            cout << "NO" << endl;
        }
        else {
            cout << "YES" << endl;
        }
    }
}