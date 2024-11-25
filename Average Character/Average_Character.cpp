#include <math.h>
#include <utility>
#include <vector>
#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int main() {
    string s;
    getline(cin, s);
    int res = 0;
    for(auto i : s) {
        res += i;
        // cout << res << " ";        
    }
    cout << (char)(res / s.size());
}