#include <utility>
#include <queue>
#include <unordered_set>
#include <iostream>
using namespace std;
int main() {
    long long n;
    cin >> n;
    cout << n << " ";
    while (n != 1) {
        if(n%2 == 0) {
            n = n/2;
        }
        else {
            n *= 3;
            n++;
        }
        cout << n << " ";
    }
}