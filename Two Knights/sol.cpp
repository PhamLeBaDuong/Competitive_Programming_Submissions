#include <math.h>
#include <iostream>

using namespace std;

// int factorial(int n) {
//     int res = 1;
//     for(int i = 2; i <= n; i++) {
//         res *= i;
//     }
//     return res;
// }

int main() {
    long long int n;
    cin >> n;
    for(long long int i = 1; i <= n; i++) {
        if(i == 1) {
            cout << 0 << endl;
            continue;
        }
        cout << (i*i*(i*i-1))/2 - (i-1)*(i-2)*2*2 << endl;
    }
}