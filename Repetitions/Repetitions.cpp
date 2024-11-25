#include <utility>
#include <queue>
#include <unordered_set>
#include <iostream>
using namespace std;
int main() {
    string s;
    cin >> s;
    long long count = 0;
    long long res = -1;
    char prev = s[0];
    for(auto i : s) {
        if(i == prev) {
            count++;
        }
        else {
            res = max(res, count);
            count = 1;
        }
        prev = i;
    }
    res = max(res, count);
    cout << res;
}