#include <utility>
#include <queue>
#include <unordered_set>
#include <iostream>
using namespace std;
int main() {
    long long n;
    cin >> n;
    long long total = 0;
    for(long long i = 1; i < n; i++) {
        long long j;
        cin >> j;
        total += j;
    }
    cout << n*(n+1)/2-total;
}