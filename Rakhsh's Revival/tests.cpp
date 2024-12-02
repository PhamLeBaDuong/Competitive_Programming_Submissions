#include <iostream>
#include <vector>
#include <string>
#include <random>
#include <algorithm>
using namespace std;

// Your original solution function here
int originalSolution(int n, int m, int k, string s) {
    vector<int> arr;
    vector<vector<int>> range;
    int temp = 0;
    int temp1 = 0;
    for(int i = 0; i < s.size(); i++) {
        if(s[i] == '0') {
            if(temp == 0) {
                temp1 = i;
            }
            temp++;
        }
        else if(temp != 0) {
            arr.push_back(temp);
            range.push_back({temp1, i-1});
            temp = 0;
        }
    }
    int nn = s.size();
    if(temp != 0) {
        arr.push_back(temp);
        range.push_back({temp1, nn-1});
    }
    long long res = 0;
    for(int i = 0; i < arr.size(); i++)
    {
        res += ceil((double)(arr[i])/(m-1+k)) - (arr[i]%(m-1+k) > 0 && arr[i]%(m-1+k) <= (m-1) ? 1 : 0);
        long long outbits = arr[i]%(m-1+k) <= (m-1) ? 0 : k-(arr[i]%(m-1+k) - (m-1));
        if(i < arr.size()-1) {
            arr[i+1] -= max((long long)(0),outbits-(range[i+1][0] - range[i][1]-1));
        }
    }
    return res;
}

// Brute-force solution to compare against
int bruteForceSolution(int n, int m, int k, string s) {
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
    
    return timarPositions.size();
}

string generateRandomBinaryString(int n) {
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> distrib(0, 1);
    
    string s;
    for (int i = 0; i < n; i++) {
        s += to_string(distrib(gen));
    }
    return s;
}

void stressTest() {
    random_device rd;
    mt19937 gen(rd());
    
    // Test parameters
    int NUM_TESTS = 10000;
    int MAX_N = 200;
    int MAX_M = 20;
    int MAX_K = 10;
    
    for (int test = 0; test < NUM_TESTS; test++) {
        // Random parameters
        uniform_int_distribution<> n_dist(1, MAX_N);
        uniform_int_distribution<> m_dist(1, MAX_M);
        uniform_int_distribution<> k_dist(1, MAX_K);
        
        int n = n_dist(gen);
        int m = m_dist(gen);
        int k = k_dist(gen);
        
        string s = generateRandomBinaryString(n);
        
        // Compare solutions
        int bruteForce = bruteForceSolution(n, m, k, s);
        int originalSol = originalSolution(n, m, k, s);
        
        if (bruteForce != originalSol) {
            cout << "Mismatch found!" << endl;
            cout << "n: " << n << ", m: " << m << ", k: " << k << endl;
            cout << "String: " << s << endl;
            cout << "Brute Force: " << bruteForce << endl;
            cout << "Original Solution: " << originalSol << endl;
            return;
        }
    }
    
    cout << "No mismatches found in " << NUM_TESTS << " random tests!" << endl;
}

int main() {
    stressTest();
    return 0;
}