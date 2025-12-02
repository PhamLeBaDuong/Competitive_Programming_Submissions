#include <bits/stdc++.h>
using namespace std;

// Compute C(l, r) for a binary string
long long computeC(const vector<int>& s, int l, int r) {
    long long total = 0;
    for (int i = l; i <= r; i++) {
        for (int j = i; j <= r; j++) {
            int count = 0;
            for (int k = i; k <= j; k++) {
                count += s[k];
            }
            total += count;
        }
    }
    return total;
}

// Compute prefix sum contribution
long long prefixSumContribution(const vector<int>& s, int l, int r) {
    long long total = 0;
    long long running = 0;
    for (int i = l; i <= r; i++) {
        running += s[i];
        total += running;
    }
    return total;
}

// Test: Given suffix, can we uniquely determine prefix?
void testUniqueness(int n, int prefixLen, int suffixLen) {
    if (prefixLen + suffixLen > n) return;
    
    map<pair<long long, string>, set<string>> collisions;
    
    // Generate all possible suffixes
    for (int suffixMask = 0; suffixMask < (1 << suffixLen); suffixMask++) {
        vector<int> suffix(suffixLen);
        for (int i = 0; i < suffixLen; i++) {
            suffix[i] = (suffixMask >> i) & 1;
        }
        
        long long suffixC = computeC(suffix, 0, suffixLen - 1);
        long long suffixPrefixSum = prefixSumContribution(suffix, 0, suffixLen - 1);
        
        string suffixStr = "";
        for (int x : suffix) suffixStr += ('0' + x);
        
        // Generate all possible prefixes
        map<long long, set<string>> prefixMap;
        
        for (int prefixMask = 0; prefixMask < (1 << prefixLen); prefixMask++) {
            vector<int> s(n, 0);
            
            // Set prefix
            for (int i = 0; i < prefixLen; i++) {
                s[i] = (prefixMask >> i) & 1;
            }
            // Set suffix
            for (int i = 0; i < suffixLen; i++) {
                s[n - suffixLen + i] = suffix[i];
            }
            
            long long fullC = computeC(s, 0, n - 1);
            
            // Compute C_imaginary for prefix
            long long cImaginary = fullC - suffixC - suffixPrefixSum * prefixLen;
            
            string prefixStr = "";
            for (int i = 0; i < prefixLen; i++) {
                prefixStr += ('0' + s[i]);
            }
            
            prefixMap[cImaginary].insert(prefixStr);
        }
        
        // Check for collisions
        for (auto& [cImag, prefixes] : prefixMap) {
            if (prefixes.size() > 1) {
                collisions[{cImag, suffixStr}] = prefixes;
            }
        }
    }
    
    if (collisions.empty()) {
        cout << "n=" << n << ", prefix=" << prefixLen << ", suffix=" << suffixLen << " -> UNIQUE!\n";
    } else {
        cout << "n=" << n << ", prefix=" << prefixLen << ", suffix=" << suffixLen << " -> " << collisions.size() << " collisions\n";
        if (collisions.size() <= 3) {
            for (auto& [key, prefixes] : collisions) {
                cout << "  Suffix: " << key.second << ", C_imag: " << key.first << " -> ";
                for (auto& p : prefixes) cout << p << " ";
                cout << "\n";
            }
        }
    }
}

// Find all (x, m) pairs that work for given n
void findWorkingPairs(int n, int maxLen) {
    cout << "\n=== Working (prefix, suffix) pairs for n=" << n << " ===\n";
    for (int prefix = 1; prefix <= maxLen; prefix++) {
        for (int suffix = 0; suffix <= maxLen; suffix++) {
            if (prefix + suffix > n) continue;
            testUniqueness(n, prefix, suffix);
        }
    }
}

// Explore if querying multiple ranges helps
void exploreMultipleRanges(int n) {
    cout << "\n=== Exploring multiple range queries for n=" << n << " ===\n";
    
    // Test: Can we determine full string with 2 queries?
    // Query C(1, n) and C(k, n) for various k
    
    for (int k = n/2; k < n; k++) {
        map<pair<long long, long long>, set<string>> patterns;
        
        for (int mask = 0; mask < (1 << n); mask++) {
            vector<int> s(n);
            for (int i = 0; i < n; i++) {
                s[i] = (mask >> i) & 1;
            }
            
            long long c1 = computeC(s, 0, n - 1);
            long long c2 = computeC(s, k, n - 1);
            
            string str = "";
            for (int x : s) str += ('0' + x);
            
            patterns[{c1, c2}].insert(str);
        }
        
        // Count unique patterns
        int unique = 0;
        for (auto& [key, strs] : patterns) {
            if (strs.size() == 1) unique++;
        }
        
        cout << "n=" << n << ", query C(1," << n << ") and C(" << k << "," << n << "): "
             << unique << "/" << (1 << n) << " unique (" 
             << (100.0 * unique / (1 << n)) << "%)\n";
    }
}

// Test information from overlapping queries
void testOverlappingQueries(int n) {
    cout << "\n=== Testing overlapping query patterns for n=" << n << " ===\n";
    
    // Pattern: Query C(1,n), C(1,n-1), C(1,n-2), ...
    for (int numQueries = 2; numQueries <= min(n, 5); numQueries++) {
        map<vector<long long>, set<string>> patterns;
        
        for (int mask = 0; mask < (1 << n); mask++) {
            vector<int> s(n);
            for (int i = 0; i < n; i++) {
                s[i] = (mask >> i) & 1;
            }
            
            vector<long long> queries;
            for (int q = 0; q < numQueries; q++) {
                queries.push_back(computeC(s, 0, n - 1 - q));
            }
            
            string str = "";
            for (int x : s) str += ('0' + x);
            
            patterns[queries].insert(str);
        }
        
        int unique = 0;
        for (auto& [key, strs] : patterns) {
            if (strs.size() == 1) unique++;
        }
        
        cout << numQueries << " queries C(1,n) through C(1,n-" << (numQueries-1) << "): "
             << unique << "/" << (1 << n) << " unique\n";
    }
}

void testLargeN() {
    for (int n = 16; n <= 24; n += 2) {
        cout << "\n=== Testing n=" << n << " ===\n";
        for (int prefix = 3; prefix <= 6; prefix++) {
            for (int suffix = prefix; suffix <= prefix + 3; suffix++) {
                if (prefix + suffix > n) continue;
                testUniqueness(n, prefix, suffix);
            }
        }
    }
}

int main() {
    // Test small values first
    cout << "=== Testing n=10 ===\n";
    findWorkingPairs(10, 8);
    
    cout << "\n=== Testing n=12 ===\n";
    findWorkingPairs(12, 8);
    
    // Explore alternative query strategies
    exploreMultipleRanges(8);
    testOverlappingQueries(8);
    
    // Test specific promising combinations for larger n
    cout << "\n=== Testing larger n with specific pairs ===\n";
    testUniqueness(15, 5, 6);
    testUniqueness(15, 6, 7);
    testUniqueness(20, 5, 6);
    testUniqueness(20, 6, 7);

    testUniqueness(2025, 5, 4);
testUniqueness(100, 5, 4);
testUniqueness(50, 5, 4);

    // testLargeN();
    
    return 0;
}