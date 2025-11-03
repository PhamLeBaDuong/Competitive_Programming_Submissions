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
    int n;
    cin >> n;
    vector<pii> a(n);
    double score = 0;
    int maxx = INT_MIN;
    int target = -1;
    for(int i = 0; i < n; i++) {
        cin >> a[i].first >> a[i].second;
        score += a[i].first*a[i].second;
    }
    sort(a.begin(), a.end());
    for(int i = 0; i < n; i++) {
        if(a[i].second > maxx) {
            maxx = a[i].second;
            target = i;
        }
    }
    double res = 0;
    int dir = 0;
    if(score < 0) {
        if(a[target].first < 0) {
            dir = 1;
        }
        else {
            dir = -1;
        }
    }
    else {
        if(a[target].first < 0) {
            dir = -1;
        }
        else {
            dir = 1;
        }
    }
    int curr_weight = a[target].second;
    int count = 1;
    while(score != 0) {
        if() {
            
        }
    }
}