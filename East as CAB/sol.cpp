#include <bits/stdc++.h>

using namespace std;

unordered_set<string> processed;
unordered_set<string> discovered;
vector<string> res;
bool has_cycle = false;


vector<string> split_utf8(const string &s) {
    vector<string> out;
    size_t i = 0;
    while (i < s.size()) {
        unsigned char c = s[i];
        size_t len = 1;
        if ((c & 0x80) == 0x00) len = 1;             // 0xxxxxxx
        else if ((c & 0xE0) == 0xC0) len = 2;        // 110xxxxx
        else if ((c & 0xF0) == 0xE0) len = 3;        // 1110xxxx
        else if ((c & 0xF8) == 0xF0) len = 4;        // 11110xxx
        // fallback (shouldn't happen for valid UTF-8)
        if (i + len > s.size()) len = s.size() - i;
        out.push_back(s.substr(i, len));
        i += len;
    }
    return out;
}

void topo(unordered_map<string, unordered_set<string>>& adj_list, string curr) {
    // cout << "Visiting: " << curr << "\n";
    if (has_cycle) {
        return;
    }

    if (discovered.find(curr) != discovered.end()) {
        return;
    }

    if (processed.find(curr) != processed.end()) {
        return;
    }

    discovered.insert(curr);
    for (auto& next : adj_list[curr]) {
        if (discovered.find(next) != discovered.end()) {
            if (processed.find(next) == processed.end()) {
                has_cycle = true;
                return;
            }
            continue;
        }
        topo(adj_list, next);
    }

    processed.insert(curr);
    res.push_back(curr);
}

int main() {
    int n;
    cin >> n;
    unordered_map<string, int> outdeg;
    unordered_map<string, int> in_deg;
    vector<string> raw_strs(n);
    vector<vector<string>> strs(n);
    for (int i = 0; i < n; i++) {
        cin >> raw_strs[i];
        // for (auto c : raw_strs[i]) {
            //     outdeg[c] = 0;
            //     in_deg[c] = 0;
            // }
        // }
    }
    for(int i = 0; i < n; i++) {
        strs[i] = split_utf8(raw_strs[i]);
        for(auto& c : strs[i]) {
            cout << c;
        }
        cout << endl;
        for(auto& str : strs[i]) {
            outdeg[str] = 0;
            in_deg[str] = 0;
        }
    }
        
    // cout << in_deg.size() << "\n";
    unordered_map<string, unordered_set<string>> adj_list;

    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) {
            for (int k = 0; k < min(strs[i].size(), strs[j].size()); k++) {
                if (strs[i][k] != strs[j][k]) {
                    adj_list[strs[i][k]].insert(strs[j][k]);
                    outdeg[strs[i][k]]++;
                    in_deg[strs[j][k]]++;
                    break;
                }
            }
        }
    }

    int out_count = 0;
    for (auto& key_val : outdeg) {
        if (key_val.second == 0) {
            out_count++;
        }
    }

    int in_count = 0;
    for (auto& key_val : in_deg) {
        // cout << key_val.first << " " << key_val.second << "\n";
        if (key_val.second == 0) {
            topo(adj_list, key_val.first);
            in_count++;
        }
    }

    if (has_cycle) {
        cout << "IMPOSSIBLE";
        return 0;
    }
    if (out_count > 1 || in_count > 1) {
        cout << "AMBIGUOUS";
        return 0;
    }
    
    for (int i = res.size() - 1; i >= 0; i--) {
        // cout << "OK\n";
        cout << res[i];
    }
}