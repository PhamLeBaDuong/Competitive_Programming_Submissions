#include <utility>
#include <queue>
#include <unordered_set>
#include <iostream>
using namespace std;
int main() {
    long long n;
    cin >> n;
    long long curr = 0;
    long long res = 0;
    for (int i = 1; i <= n; i++) {
        long long j;
        cin >> j;
        if(curr > j && curr != 0) {
            res += curr-j;
        }
        curr = max(curr,j);
    }
    cout << res;
}