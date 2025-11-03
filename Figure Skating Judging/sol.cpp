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
    double n, k;
    cin >> n >> k;
    vector<double> scores(n);
    double sum = 0;
    double badness = 0;
    for (int i = 0; i < n; i++) {
        cin >> scores[i];
        sum += scores[i];
    }
    for(int i = 0; i < n; i++) {
        badness += pow(scores[i] - (sum/(n-1)), 2);
    }

    double res = INT_MAX;
    for(int i = 0; i < n; i++) {

        // res = min(res, badness - 2*scores[i]*sum/(n-1) + (scores[i]*scores[i])/(n-1) + ((2*scores[i])/(n-1))*(sum-scores[i]) - pow(sum/(n-1) - scores[i], 2));
        res = min(res, badness - scores[i]*scores[i]/(n-1) - pow(sum/(n-1) - scores[i], 2));
    }
    cout << res << endl;
}