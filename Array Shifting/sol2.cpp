#include <bits/stdc++.h>
using namespace std;

const long long MOD = 1e9 + 7;

long long power(long long base, long long exp, long long mod) {
    long long result = 1;
    while (exp > 0) {
        if (exp % 2 == 1) result = (result * base) % mod;
        base = (base * base) % mod;
        exp /= 2;
    }
    return result;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n, k;
    cin >> n >> k;
    
    vector<long long> b(n);
    for (int i = 0; i < n; i++) {
        cin >> b[i];
    }
    
    vector<int> a(n + k, -1); // -1 means undetermined
    
    // Step 1: Mark definite zeros
    for (int i = 0; i < n - 1; i++) {
        if (b[i] != 0 && b[i + 1] == 0) {
            // a[i + k + 1] must be 0
            if (a[i + k + 1] == -1) {
                a[i + k + 1] = 0;
            } else if (a[i + k + 1] != 0) {
                cout << -1 << endl;
                return 0;
            }
        }
        if (b[i] == 0 && b[i + 1] != 0) {
            // a[i] must be 0
            if (a[i] == -1) {
                a[i] = 0;
            } else if (a[i] != 0) {
                cout << -1 << endl;
                return 0;
            }
        }
    }
    
    // Step 2: Check if b[i] = 0 implies at least one zero in window
    for (int i = 0; i < n; i++) {
        if (b[i] == 0) {
            bool hasZero = false;
            for (int j = i; j <= i + k; j++) {
                if (a[j] == 0) {
                    hasZero = true;
                    break;
                }
            }
            // If no zero is marked yet, we need at least one
            // We'll handle this later
        }
    }
    
    // Step 3: For positions still undetermined, use recurrence for non-zero b values
    // Try to determine a[0] first
    
    // Find first non-zero b[i]
    int firstNonZero = -1;
    for (int i = 0; i < n; i++) {
        if (b[i] != 0) {
            firstNonZero = i;
            break;
        }
    }
    
    if (firstNonZero == -1) {
        // All b values are zero, array can be all zeros
        for (int i = 0; i < n + k; i++) {
            cout << 0;
            if (i < n + k - 1) cout << " ";
        }
        cout << endl;
        return 0;
    }
    
    // Try to set initial values and propagate
    // We'll try a[0] = 1 or 2 (if not already determined as 0)
    
    for (int tryVal = 0; tryVal <= 2; tryVal++) {
        vector<int> attempt(a); // copy
        
        // Set a[0] if undetermined
        if (attempt[0] == -1) {
            attempt[0] = tryVal;
        } else if (attempt[0] != tryVal && tryVal > 0) {
            continue;
        }
        
        // Propagate using recurrence
        bool valid = true;
        
        for (int i = 0; i < n - 1 && valid; i++) {
            if (b[i] == 0 || b[i + 1] == 0) {
                // Handle zero cases
                if (b[i] != 0 && b[i + 1] == 0) {
                    if (attempt[i + k + 1] == -1) {
                        attempt[i + k + 1] = 0;
                    }
                } else if (b[i] == 0 && b[i + 1] != 0) {
                    if (attempt[i] == -1) {
                        attempt[i] = 0;
                    }
                }
                continue;
            }
            
            // Both non-zero
            // b[i+1] * a[i] = b[i] * a[i+k+1]
            
            if (attempt[i] != -1 && attempt[i] != 0) {
                // Determine a[i+k+1]
                long long numerator = (b[i + 1] * attempt[i]) % MOD;
                long long denominator = b[i];
                
                if (numerator % denominator != 0) {
                    valid = false;
                    break;
                }
                
                long long val = numerator / denominator;
                
                if (val < 1 || val > 2) {
                    valid = false;
                    break;
                }
                
                if (attempt[i + k + 1] == -1) {
                    attempt[i + k + 1] = val;
                } else if (attempt[i + k + 1] != val) {
                    valid = false;
                    break;
                }
            }
        }
        
        if (!valid) continue;
        
        // Fill remaining undetermined values
        // For windows with b[i] = 0, ensure at least one zero
        for (int i = 0; i < n; i++) {
            if (b[i] == 0) {
                bool hasZero = false;
                int undetermined = -1;
                for (int j = i; j <= i + k; j++) {
                    if (attempt[j] == 0) hasZero = true;
                    if (attempt[j] == -1) undetermined = j;
                }
                if (!hasZero && undetermined != -1) {
                    attempt[undetermined] = 0;
                }
            }
        }
        
        // Fill any remaining with 1
        for (int i = 0; i < n + k; i++) {
            if (attempt[i] == -1) attempt[i] = 1;
        }
        
        // Verify the solution
        bool correct = true;
        for (int i = 0; i < n && correct; i++) {
            long long product = 1;
            for (int j = i; j <= i + k; j++) {
                product = (product * attempt[j]) % MOD;
            }
            if (product != b[i]) {
                correct = false;
            }
        }
        
        if (correct) {
            for (int i = 0; i < n + k; i++) {
                cout << attempt[i];
                if (i < n + k - 1) cout << " ";
            }
            cout << endl;
            return 0;
        }
    }
    
    cout << -1 << endl;
    return 0;
}