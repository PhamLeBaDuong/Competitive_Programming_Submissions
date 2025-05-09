#include <math.h>
#include <iostream>
#include <string>
#include <vector>
#include <climits>
#include <unordered_map>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    vector<int> a(m);
    unordered_map<int, int> mp;
    for(int i = 0; i < m; i++) {
        cin >> a[i];
    }
    // cout << endl;
    long long int curr = 0;
    for(int i = 0; i < m; i++) {
        curr += n - i - 1 + mp[a[i]];
        mp[a[i]] = i+1;
        cout << curr << endl;
    }

}