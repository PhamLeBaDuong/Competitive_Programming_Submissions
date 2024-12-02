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
        int n, k;
        cin >> n >> k;
        priority_queue<int, vector<int>, less<int>> pq;
        for(int i = 0; i < n; i++) {
            int a;
            cin >> a;
            pq.push(a);
        }
        int res = 0;
        int temp = INT_MAX;
        int count = 0;
        while(!pq.empty()){
            if(k-count-pq.top() < temp && k >= count+pq.top()) {
                temp = k-count-pq.top();
                count += pq.top();
                pq.pop();
            }
            else {
                break;
            }
        }
        cout << temp << endl;

    }
}