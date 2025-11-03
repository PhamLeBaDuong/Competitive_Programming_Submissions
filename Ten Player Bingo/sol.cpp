#include <math.h>
#include <iostream>
#include <string>
#include <utility>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <queue>
#include <unordered_set>
#include <climits>
using namespace std;
typedef pair<pair<int, int>, int> pipii;
typedef pair<int, int> pii;
typedef long long int lli;

int main() {
    int lastNumber = -1;
    for(int i = 1; i <= 100; i++) {
        cin >> lastNumber;
    }    
    cout << (lastNumber%10 == 0 ? 10 : lastNumber%10) << endl;
}