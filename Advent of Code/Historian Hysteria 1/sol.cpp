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
    priority_queue<int, vector<int>, greater<int>> pq1;
    priority_queue<int, vector<int>, greater<int>> pq2;
    while(true) {
        int i, j;
        cin >> i >> j;
        if(i == 0 && j == 0) {
            break;
        }
        pq1.push(i);
        pq2.push(j);

    }
    int res = 0;
    while(!pq1.empty()) {
        res += abs(pq1.top() - pq2.top());
        pq1.pop();
        pq2.pop();
    }
    cout << res << endl;

}