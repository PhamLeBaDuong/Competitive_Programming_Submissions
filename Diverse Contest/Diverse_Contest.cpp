#include <math.h>
#include <iostream>
#include <unordered_set>
#include <utility>
#include <vector>
#include <unordered_map>
using namespace std;

int bt(int curr, int count, int k, 
        unordered_map<int, vector<string>> &mp,
        unordered_map<string, int> list, int &numProblems) {
    // cout << curr << " " << count << endl;
    for(auto i : mp[curr]) {
        list[i]++;
        if(list[i] > k/2) {
            return 0;
        }
    }
    if(count == k) {
        return 1;
    }
    int res = 0;
    for(int i = curr+1; i < numProblems; i++) {
        res += bt(i, count+1, k, mp, list, numProblems);
    }
    return res;
}

int main() {
    int numProblems;
    cin >> numProblems;
    int k;
    cin >> k;
    unordered_map<int, vector<string>> mp;
    unordered_map<string, int> list;
    for(int i = 0; i < numProblems; i++) {
        int numTopics;
        cin >> numTopics;
        for(int ii = 1; ii <= numTopics; ii++) {
            string strr;
            cin >> strr;
            mp[i].push_back(strr);
        }
    }
    int res = 0;
    for(int i = 0; i < numProblems; i++) {
        res += bt(i, 1, k, mp, list, numProblems);
    }
    cout << res;
}