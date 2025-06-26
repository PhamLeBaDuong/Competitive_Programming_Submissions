#include <math.h>
#include <iostream>
#include <string>
#include <vector>
#include <climits>
#include <unordered_map>

using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    vector<vector<int>> a(n, vector<int>(k,0));
    unordered_map<int, int> preCurr;
    unordered_map<int, int> sufCurr;
    int numOverlap = 1;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < k; j++) {
            cin >> a[i][j];
            sufCurr[a[i][j]]++;
            if(sufCurr[a[i][j]] > 1) {
                numOverlap /= sufCurr[a[i][j]]-1;
                numOverlap *= sufCurr[a[i][j]];
            }
        }
    }
    cout << endl;
    for(int i = 0; i < n; i++) {
        int temp = k;
        for(int j = 0; j < k; j++) {
            if(sufCurr[a[i][j]] > 1) {
                sufCurr[a[i][j]]--;
                temp--;
            }
            else if(sufCurr[a[i][j]] == 1) {
                sufCurr.erase(a[i][j]);
            }
        }
        if(temp == 0) {
            cout << (double)0 << endl;
        }
        else {
            cout << (1-(double)temp/(i*k+temp+(n*k-i*k-k+temp))) << endl;
        }
        for(int j = 0; j < k; j++) {
            preCurr[a[i][j]]++;
        }
    }
}