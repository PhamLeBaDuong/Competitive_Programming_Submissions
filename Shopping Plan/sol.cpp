#include <climits>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <string>
#include <thread>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>
#include <set>
#include <algorithm>
#include <stack>
#include <sstream>
#include <cmath>
#include <cfloat>
#include <iomanip>

using namespace std;

vector<string> split(const string &s, char delimiter) {
    vector<string> tokens;
    stringstream ss(s);
    string token;
    while (getline(ss, token, delimiter)) {
        tokens.push_back(token);
    }
    return tokens;
}
struct State{
    int x;
    int y;
    double cost;
    bool has_per;
    vector<bool> items_bought;
    State(int _x, int _y, double _cost, vector<bool> _items_bought, bool _has_per = false)
        : x(_x), y(_y), cost(_cost), items_bought(items_bought), has_per(_has_per) {}
};

int main() {
    string tempT;
    getline(cin, tempT);
    int t;
    t = stoi(tempT);
    int case_num = 0;
    while(t--) {
        // vector<vector<map<set<int>, int>>> visited(1000);
        map<pair<int, int>, map<vector<bool>, double>> visited;
        
        case_num++;
        int num_items, num_stores, price_of_gas;
        string tempp;
        getline(cin, tempp);
        // cin >> num_items >> num_stores >> price_of_gas;
        auto temppp = split(tempp, ' ');
        num_items = stoi(temppp[0]);
        num_stores = stoi(temppp[1]);
        price_of_gas = stoi(temppp[2]);
        vector<string> items(num_items);
        unordered_map<int, bool> is_per;
        unordered_map<int, vector<vector<int>>> mp_item;
        unordered_map<string, int> item_to_index;
        getline(cin, tempp);
        items = split(tempp, ' ');
        for(int i = 0; i < num_items; i++) {
            // cin >> items[i];
            item_to_index[items[i]] = i;
            if(items[i][items[i].size()-1] == '!') {
                items[i].pop_back();
                is_per[i] = true;
            }
            else {
                is_per[i] = false;
            }
        }
        for(int i = 0; i < num_stores; i++) {
            string temp;
            getline(cin, temp);
            vector<string> tockenized = split(temp, ' ');
            // cout << temp << "\n";
            // for(auto &it : tockenized) {
            //     cout << it << "|";
            // }
            int x = stoi(tockenized[0]);
            int y = stoi(tockenized[1]);
            for(int j = 2; j < tockenized.size(); j++) {
                vector<string> temp = split(tockenized[j], ':');
                string item_name = temp[0];
                int item_price = stoi(temp[1]);
                mp_item[item_to_index[item_name]].push_back({x, y, item_price});
            }
        }
        // for(auto &i : mp_item) {
        //     cout << i.first << ":\n";
        //     for(auto &j : i.second) {
        //         cout << j[0] << " " << j[1] << " " << j[2] << "\n";
        //     }
        // }
        // cout << "\n";
        // for(auto &it : is_per) {
        //     cout << it.first << " " << it.second << "\n";
        // }
        // cout << "\n";
        auto cmp = [](const State &a, const State &b) {
            return a.cost > b.cost;
        };
        // priority_queue<State, vector<State>, decltype(cmp)> pq(cmp);
        queue<State> pq;
        pq.push(State(0, 0, 0, vector<bool>(num_items, false)));
        double final_cost = DBL_MAX;
        while(!pq.empty()) {
            State curr = pq.front();
            // State curr = pq.top();
            pq.pop();
            if(curr.items_bought.size() == num_items) {
                final_cost = min(final_cost, curr.cost + sqrt(pow(curr.x, 2) + pow(curr.y, 2))*price_of_gas);
                continue;
            }
            cout << "wth" << endl;
            for(auto &item : mp_item) {
                if(curr.items_bought[item.first] == false) {
                    for(auto &store : item.second) {
                        double dist = sqrt(pow(store[0]-curr.x, 2) + pow(store[1]-curr.y, 2));
                        double new_cost = curr.cost + dist*price_of_gas + store[2];
                        auto new_items_bought = curr.items_bought;
                        new_items_bought[item.first] = true;
                        int next_x = store[0];
                        int next_y = store[1];
                        if(curr.x != next_x || curr.y != next_y) {
                            if(curr.has_per) {
                                new_cost += (sqrt(pow(store[0], 2) + pow(store[1], 2)) + sqrt(pow(curr.x, 2) + pow(curr.y, 2)))*price_of_gas;
                            }
                            curr.has_per = is_per[item.first];
                        }
                        // else {
                            
                        // }
                        if(visited[{next_x, next_y}].find(new_items_bought) != visited[{next_x, next_y}].end()) {
                            if(visited[{next_x, next_y}][new_items_bought] <= new_cost) {
                                continue;
                            }
                        }
                        visited[{next_x, next_y}][new_items_bought] = new_cost;
                        // if(is_per[item.first]) {
                        //     curr.has_per = true;
                        // }
                        // if(is_per[item.first]) {
                        //     next_x = 0;
                        //     next_y = 0;
                        //     new_cost += sqrt(pow(store[0], 2) + pow(store[1], 2))*price_of_gas;
                        // }
                        // else {
                        //     next_x = store[0];
                        //     next_y = store[1];
                        // }
                        pq.push(State(store[0], store[1], new_cost, new_items_bought, curr.has_per));
                    }
                }
            }
        }
        cout << "Case #" << case_num << ": " << fixed << setprecision(9) << final_cost << "\n";
    }
}