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
int MAX_N = 1000001;

void precompute(vector<int>& phi) {
	for (int i = 1; i < MAX_N; i++) { phi[i] = i; }
	for (int i = 2; i < MAX_N; i++) {
		// If i is prime
		if (phi[i] == i) {
			for (int j = i; j < MAX_N; j += i) { phi[j] -= phi[j] / i; }
		}
	}
}

void precompute_maxdiv(vector<int>& maxdiv) {
    for(int i = 1; i < MAX_N; i++) {
        for(int j = i; j < MAX_N; j += i) {
            maxdiv[j] = i;
        }
    }
}

long long int solve(int n, vector<int>& phi) {
    long long int res = 0;
        
}

int main() {
    vector<int> phi(MAX_N);
    vector<int> maxdiv(MAX_N);
    precompute_maxdiv(maxdiv);
    precompute(phi);
    while (true) {
        int n;
        cin >> n;
        if(n == 0) {
            break;
        }

    }
}