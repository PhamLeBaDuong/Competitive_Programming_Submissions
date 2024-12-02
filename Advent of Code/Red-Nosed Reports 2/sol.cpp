#include <math.h>
#include <iostream>
#include <string>
#include <utility>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <queue>
#include <unordered_set>
#include <sstream>
using namespace std;
bool bt(int i, vector<int> &arr, int prev, int state, int tol) {
    // cout << i << " " << prev << " " << state << " " << tol << endl;
    if(tol > 1) {
        return false;
    }
    if(i >= arr.size()) {
        return true;
    }
    int cal = arr[i]-arr[prev];
    if(state == 0) {
        bool res = false;
        if(abs(cal) != 0 && abs(cal) <= 3) {
            res = res || bt(i+1, arr, i, (arr[i] > arr[prev] ? 1 : -1), tol);
        }
        res = res || bt(i+1, arr, prev, state, tol+1) || bt(i+1, arr, i, state, tol+1);
        return res;
    }
    if(abs(cal) > 3 || cal == 0 || (state * (cal > 0 ? 1 : -1) < 0)) {
        return bt(i+1, arr, prev, state, tol+1) || bt(i, arr, prev-1, state, tol+1);        
    }
    else {
        return bt(i+1, arr, i, state, tol);
    }
}
int main() {
    int res = 0;
    while(true) {
        vector<int> arr;
        string str;
        getline(cin,str);
        stringstream ss(str);
        string num;
        while(ss >> num) {
            arr.push_back(stoi(num));
        }
        if(arr[0] == 0) {
            break;
        }
        res += (bt(1, arr, 0, 0, 0) ? 1 : 0);
        // cout << res << endl;
    }
    std::cout << res;
}