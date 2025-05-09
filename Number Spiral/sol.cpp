#include <math.h>
#include <iostream>

using namespace std;
int main() {
    ios::ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    long long int t;
    cin >> t;
    while(t--) {
        long long int i, j;
        cin >> i >> j;
        long long int larger = max(i, j);
        long long int lesser = min(i, j);
        cout << (larger-1)*(larger-1) + ((lesser == j && larger & 1) || (lesser == i && !(larger & 1)) ? lesser : (larger*2-lesser)) << endl;
    }
}