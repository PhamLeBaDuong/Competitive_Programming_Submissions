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
using namespace std;
typedef pair<pair<int, int>, int> pipii;
typedef pair<int, int> pii;
int main() {
    auto cmp = [](const pipii &a, int t) {
        return a.first.first <= t;
    };

    int p, n;
    cin >> p >> n;
    vector<int> a(n);
    vector<vector<pipii>> al(p);
    vector<vector<pipii>> ar(p);
    for (int i = 0; i < n; i++) {
        int t, f;
        string s;
        cin >> t >> f;
        cin >> s;
        if(s == "L") {
            int minn = INT_MAX;
            int tempRes = -1;
            for(int j = 0; j < p; j++) {
                auto temp = lower_bound(al[j].begin(), al[j].end(), t, cmp);
                if(al[j].end() - temp < minn) {
                    minn = al[j].end() - temp;
                    tempRes = j;
                }
            }
            // auto temp = al[tempRes].empty() ? (t + f) : (max(al[tempRes][al[tempRes].size() - 1].first.first == 0 ? al[tempRes][al[tempRes].size() - 1].second : al[tempRes][al[tempRes].size() - 1].first.first, t) + f);
            auto temp = al[tempRes].empty() ? (t + f) : (max(al[tempRes][al[tempRes].size() - 1].first.first, t) + f);
            a[i] = temp;
            if(al[tempRes].empty()) {
                al[tempRes].push_back({{0, temp},t});
            }
            else if (al[tempRes][al[tempRes].size() - 1].first.second == 0 || al[tempRes][al[tempRes].size() - 1].first.first >= al[tempRes][al[tempRes].size() - 1].first.second || t >= al[tempRes][al[tempRes].size()-1].first.second) {
                al[tempRes].push_back({{al[tempRes][al[tempRes].size() - 1].first.first, temp}, temp-f});
            }
            else {
                al[tempRes].push_back({{temp, al[tempRes][al[tempRes].size() - 1].first.second}, temp-f});
            }     
            for(auto &j : al) {
                for(auto &i : j) {
                    cout << "[{" << i.first.first << ":" << i.first.second << "}, " << i.second << "], ";
                }
                cout << endl;
            }
            cout << endl;
        }
        else {
            int minn = INT_MAX;
            int tempRes = -1;
            for(int j = 0; j < p; j++) {
                auto temp = lower_bound(ar[j].begin(), ar[j].end(), t, cmp);
                if(ar[j].end() - temp < minn) {
                    minn = ar[j].end() - temp;
                    tempRes = j;
                }
                cout << ar[j].end() - temp << ", ";
            }
            cout << endl;
            
            // auto temp = ar[tempRes].empty() ? (t + f) : (max(ar[tempRes][ar[tempRes].size() - 1].first.first == 0 ? ar[tempRes][ar[tempRes].size() - 1].second : ar[tempRes][ar[tempRes].size() - 1].first.first, t) + f);
            auto temp = ar[tempRes].empty() ? (t + f) : (max(ar[tempRes][ar[tempRes].size() - 1].first.first, t) + f);
            a[i] = temp;
            if(ar[tempRes].empty()) {
                ar[tempRes].push_back({{0, temp},t});
            }
            else if (ar[tempRes][ar[tempRes].size() - 1].first.second == 0 || ar[tempRes][ar[tempRes].size() - 1].first.first >= ar[tempRes][ar[tempRes].size() - 1].first.second || t >= ar[tempRes][ar[tempRes].size()-1].first.second) {
                ar[tempRes].push_back({{ar[tempRes][ar[tempRes].size() - 1].first.first, temp}, temp-f});
            }
            else {
                ar[tempRes].push_back({{temp, ar[tempRes][ar[tempRes].size() - 1].first.second}, temp-f});
            } 
            for(auto &j : ar) {
                for(auto &i : j) {
                    cout << "[{" << i.first.first << ":" << i.first.second << "}, " << i.second << "], ";
                }
                cout << endl;
            } 
            cout << endl;   
        }
    }
    for(int i = 0; i < n; i++) {
        cout << a[i] << endl;
    }
}