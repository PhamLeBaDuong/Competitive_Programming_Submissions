#include <math.h>
#include <iostream>
#include <unordered_set>
#include <utility>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <queue>
#include <cmath>
#define _USE_MATH_DEFINES
using namespace std;
typedef long long int lli;
int main() {
    int h, v;
    cin >> h >> v;
    if(v >= 0 && v <= 180) {
        cout << "safe" << endl;
    }
    else {
        int temp = (v <= 270 ? v - 180 : 360 - v);
        cout << (int)(h/sin(temp*3.14159265358979323846/180)) << endl;
    }
}