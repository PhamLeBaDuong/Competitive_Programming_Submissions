#include <math.h>
#include <iostream>
#include <string>
#include <utility>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <queue>
#include <unordered_set>
#include <climits>
#include <set>
using namespace std;
typedef pair<pair<int, int>, int> pipii;
typedef pair<int, int> pii;
int main() {
    int n;
    cin >> n;
    vector<int> arr(n);
    // vector<pii> a;
    vector<int> a;
    set<int> b;
    unordered_map<int, int> m;
    multiset<pii> s;
    
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
        // a.push_back({arr[i], i});
        a.push_back(arr[i]);
        m[arr[i]] = i;
        // s.insert({i, arr[i]});
        b.insert(i);
    }
    sort(a.begin(), a.end());
    int count = 0;
    for(int i = 0; i < n; i++) {
        auto temp = b.find(m[a[i]]);
        count += distance(b.begin(), temp) + *b.begin() - i;

        b.erase(m[a[i]]);
        // if(a[i] != arr[i]) {
        //     count++;
        //     swap(arr[i], arr[m[a[i]]]);
        //     auto temp = m[a[i]];
        //     m[a[i]] = i;
        //     m[arr[i]] = temp;
        //     // count++;
        // }
    }
    cout << count << endl;
}