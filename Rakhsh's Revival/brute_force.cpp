#include <math.h>
#include <iostream>
#include <string>
#include <utility>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <queue>
#include <unordered_set>
using namespace std;
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m, k;
        cin >> n >> m >> k;
        string s;
        cin >> s;
        
        // Implement a straightforward, potentially inefficient but clearly correct solution
        vector<int> timarPositions;
        
        for (int i = 0; i < n; i++) {
            // Check if current segment of m consecutive spots is all weak
            bool isWeakSegment = true;
            for (int j = i; j < min(i + m, n); j++) {
                if (s[j] == '1') {
                    isWeakSegment = false;
                    break;
                }
            }
            
            // If weak segment found, apply Timar
            if (isWeakSegment) {
                int timarStart = min(n - k, max(0, i));
                for (int j = timarStart; j < timarStart + k; j++) {
                    s[j] = '1';
                }
                timarPositions.push_back(timarStart);
            }
        }
        
        cout << timarPositions.size() << endl;
    }

}