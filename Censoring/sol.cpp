#include <climits>
#include <cstdio>
#include <math.h>
#include <iostream>
using namespace std;

int main() {
    string s;
    cin >> s;
    string t;
    cin >> t;
    size_t pos = 0;
    while((pos = s.find(t,(pos < t.length() ? 0 : pos-t.length()))) != string::npos) {
        s.erase(pos,t.length());
    }
    cout << s << endl;
}