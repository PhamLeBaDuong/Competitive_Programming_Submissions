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
vector<int> findInterval(vector<vector<int>> &list, unordered_set<int> &ons) {
    int lower = INT8_MIN;
    int upper = INT8_MAX;
    for(int i = 0; i < list.size(); i++) {
        // cout << lower << " " << upper << endl;
        if(ons.find(i) != ons.end()) {
            if(lower == INT8_MIN && upper == INT8_MAX)
            {
                continue;
            }
            else {
                lower += list[i][0];
                upper += list[i][1];
            }

        }
        else {
            lower = max(lower, list[i][0]);
            upper = min(upper, list[i][1]);
        }
    }
    return {lower, upper};
}
int main() {
	freopen("traffic.in", "r", stdin);
    int n;
    cin >> n;
    vector<vector<int>> list;
    unordered_set<int> ons;
    int count = 0;
    while(count < n) {
        string str;
        int lower, upper;
        cin >> str >> lower >> upper;
        if(str == "on"){
            ons.insert(count);
            list.push_back({lower, upper});
        }
        else if(str == "off"){
            ons.insert(count);
            list.push_back({-1*upper, -1*lower});
        }
        else {
            list.push_back({lower, upper});
        }
        count++;
    }
    auto en = findInterval(list, ons);
    auto st = en;
    int index = list.size() - 1;
    while(ons.find(index) != ons.end()){
        st[0] -= list[index][0];
        st[1] -= list[index][1];
        index--;
    }
    index = 0;
    while(ons.find(index) != ons.end()){
        st[0] -= list[index][0];
        st[1] -= list[index][1];
        index++;
    }

	freopen("traffic.out", "w", stdout);
    cout << st[0] << " " << st[1] << endl;
    cout << en[0] << " " << en[1] << endl;
}