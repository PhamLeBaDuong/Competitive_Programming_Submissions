#include <math.h>
#include <utility>
#include <vector>
#include <iostream>
#include <unordered_map>
#include <unordered_set>
using namespace std;

int main() {
    string str;
    cin >> str;
    // unordered_map<char, int> mp;
    // mp['A'] = 0;
    // mp['B'] = 0;
    vector<vector<int>> list;
    for(int i = 1; i <= str.size(); i++) {
        list.push_back({i,0,0,0,0});
    }
    int curr = 0;
    for(auto i : str) {
        // mp[i]++;
        for(int j = 0; j < list.size(); j++) {
            if(i == 'A') {
                list[j][1]++;
            }
            else {
                list[j][2]++;
            }
            if(list[j][1] == list[j][0]) {
                list[j][1] = 0;
                list[j][2] = 0;
                list[j][3]++;
            }
            else if(list[j][2] == list[j][0]) {
                list[j][1] = 0;
                list[j][2] = 0;
                list[j][4]++;
            }
        }
        // if(mp['A'] > mp['B'] && mp['A'] > curr) {
        //     list.push_back({mp['A'], 0, 0, 1, 0});
        //     curr = mp['A'];
        // }
    }
    vector<int> res;
    for(auto i : list) {
        if(i[3] > i[4]) {
            res.push_back(i[0]);
        }
    }
    cout << res.size() << endl;
    for(auto i : res) {
        cout << i << " ";
    }
}