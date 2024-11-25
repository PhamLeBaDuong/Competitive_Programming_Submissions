#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int findMaxUpDownSequence(const vector<int>& arr) {
    int n = arr.size();
    if (n < 3) return 0;  // Cannot form valid sequence with less than 3 elements
    
    // For each index i:
    // inc[i] = length of longest strictly increasing sequence ending at i
    // dec[i] = length of longest strictly decreasing sequence starting at i
    vector<int> inc(n), dec(n);
    
    // Calculate longest increasing subsequence lengths ending at each position
    for (int i = 0; i < n; i++) { inc[i] = 1;  // Single element
        for (int j = 0; j < i; j++) {
            if (arr[i] > arr[j]) {
               inc[i] = max(inc[i], inc[j] + 1);
            }
        }
        cout << inc[i] << " ";
    }
    cout << endl;
    
    // Calculate longest decreasing subsequence lengths starting at each position
    for (int i = n-1; i >= 0; i--) {
        dec[i] = 1;  // Single element
        for (int j = n-1; j > i; j--) {
            if (arr[i] > arr[j]) {
                dec[i] = max(dec[i], dec[j] + 1);
            }
        }
        cout << dec[i] << " ";
    }
    cout << endl;
    
    // Find maximum valid sequence length
    // Need at least 2 elements in increasing part and 2 elements in decreasing part
    int maxLen = 0;
    for (int i = 0; i < n; i++) {
        if (inc[i] >= 2 && dec[i] >= 2) {
            // -1 because the peak element is counted twice
            maxLen = max(maxLen, inc[i] + dec[i] - 1);
        }
    }
    
    return maxLen;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t;
    cin >> t;
    
    while (t--) {
        int n;
        cin >> n;
        vector<int> arr(n);
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        
        cout << findMaxUpDownSequence(arr) << '\n';
    }
    
    return 0;
}