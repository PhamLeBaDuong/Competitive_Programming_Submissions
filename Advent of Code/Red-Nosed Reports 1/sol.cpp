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
        int state = 0;
        for(int i = 1; i < arr.size(); i++) {
            if(i == 1) {
                state = (arr[i] > arr[i-1] ? 1 : -1);
                if(abs(arr[i] - arr[i-1]) == 0 || abs(arr[i] - arr[i-1]) > 3) {
                    state = 2;
                    break;
                }
            }
            else {
                int temp = arr[i] - arr[i-1];
                if(temp == 0 || abs(temp) > 3) {
                    state = 2;
                    break;
                }
                if(state * (temp > 0 ? 1 : -1) < 0) {
                    state = 2;
                    break;
                }
            }
        }
        res += (state != 2 ? 1 : 0);

    }
    std::cout << res;
}