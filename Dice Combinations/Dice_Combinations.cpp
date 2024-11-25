#include <utility>
#include <queue>
#include <unordered_set>
#include <iostream>
#include <math.h>
using namespace std;
int main() {
    long long n;
    cin >> n;
    vector<long long> arr(n,0);
    vector<long long> count(7,0);
    count[1]=1;
    arr[0] = 1;
    for(long long i = 1; i < n; i++) {
        arr[i] = arr[i-1]*2 - count[6];
        for(int j = 6; j >= 1; j--) {
            count[j] = count[j-1];
        }
        count[1] = arr[i-1];

    }
    cout << arr[n-1];
}