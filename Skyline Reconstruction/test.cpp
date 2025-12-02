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
#include <numeric>
using namespace std;
typedef pair<pair<int, int>, int> pipii;
typedef pair<int, int> pii;
typedef long long lli;
int x = 5;
int y = 293;

unordered_map<lli, vector<string>> mp;
unordered_map<string, lli> mp2;
string bruh = "00000";
// int bruhi = 0;

lli sum_of_prefixes(const string& s) {
    lli total = 0;
    lli running = 0;
    for(char c : s) {
        running += (c - '0');
        total += running;
    }
    return total;
}

lli cal(string ss) {

    // if(s == "") return 0;
    // cout << s.size() << endl;
    vector<int> suf(ss.size(), 0);
    vector<int> s(ss.size());
    // vector<int> a = {1, 3, 5, 7, 11};
    for(int i = 0; i < ss.size(); i++) {
        s[i] = ss[i] - '0';
        // if(ss.size() == 5) {
        //     s[i] *= a[i];
        // }
        // cout << s[i];
    }
    // cout << endl;
    suf[s.size()-1] = (s[s.size()-1]);
    for(int i = s.size()-2; i >= 0; i--) {
        suf[i] = suf[i+1] + (s[i]);
    }
    suf.push_back(0);

    lli res = 0;
    for(int i = 0; i < s.size(); i++) {
        for(int j = s.size()-1; j >= i; j--) {
            res += suf[i] - suf[j+1];
        }
    }
    return res;
    // return res + sum_of_prefixes(ss);
}
/*

1100010000000: 85
0001100000000: 85
1110010000000: 118
0011100000000: 118

100
001
110
011

0001: 4
1000: 4
0010: 6
0100: 6
0101: 10
1100: 10
0011: 10
1010: 10
1101: 14
1011: 14
1110: 16
0111: 16


00001: 5
10000: 5

00010: 8
01000: 8

01001: 13
11000: 13
00011: 13
10010: 13

00101: 14
10100: 14

00110: 17
01100: 17

10011: 18
11001: 18

11010: 21
01011: 21

00111: 22
11100: 22
10110: 22
01101: 22

10111: 27
11101: 27

01111: 30
11110: 30


000: 0
100: 3
001: 3
010: 4
101: 6
110: 7
011: 7
111: 10

*/
void test(string curr, int n, int org_n) {
    // cout << curr << endl;
    if(n == 0) {
        // curr += '1';
        // cout << curr << ": " << cal(curr) << endl;
        // string bruh (org_n-1, '0');
        // string bruh = "01";
        // bruh.resize(bruhi, '0');
        // bruh = "";
        // curr += bruh;
        // cout << curr << endl;
        // cout << curr.substr(0, 8) << " " << curr.substr(4,7) << endl;
        // lli temp = cal(curr.substr(0, 10))*x+cal(curr.substr(5,5))*y;
        // lli temp = ( pow(cal(curr.substr(0, 10))*x, 2))+(pow(cal(curr.substr(5,5)), 2)*y);

        // curr[5] = '0';
        // curr.insert(curr.begin() + 2, '0');
        // curr.insert(curr.begin() + 2, '0');
        // curr.insert(curr.begin() + 2, '0');
        // curr.insert(curr.begin() + 2, '0');
        // curr.insert(curr.begin() + 2, '0');
        // curr.insert(curr.begin() + 2, '0');
        // curr += bruh;
        // cout << curr << " -> ";
        // for(int ii = 0; ii < bruhi; ii++) {
        //     curr.insert(curr.begin() + org_n - 2 , '0');
        // }
        curr += bruh;
        // curr = bruh + curr;
        // cout << curr << endl;
        lli temp = cal(curr);
        curr.pop_back();
        curr.pop_back();
        curr.pop_back();
        curr.pop_back();
        curr.pop_back();
        // curr.pop_back();
        mp2[curr] = temp;
        mp[temp].push_back(curr);
        return;
    }
    test(curr + "0", n-1, org_n);
    test(curr + "1", n-1, org_n);
}
int main() {
    lli x;
    // cin >> x;
    x = 4;
    // cin >> bruh;
    // for(int i = 1; i <= 100; i++) {
    //     mp2.clear();
    //     mp.clear();
    //     bruhi = i;
    //     test("", x, x);
    //     if(mp2.size() == mp.size()) {
    //         cout << "NO DUPLICATES FOR LENGTH " << i << endl;
    //     } 
    //     // else {
    //     //     cout << "DUPLICATES FOR LENGTH " << i << endl;
    //     // }
    // }
    // cout << "THATS IT" << endl;
    test("", x, x);
    vector<pair<string, lli>> v;
    for(auto p : mp2) {
        v.push_back({p.first, p.second});
    }
    sort(v.begin(), v.end(), [](pair<string, lli> &a, pair<string, lli> &b) {
        return a.second < b.second;
    });
    lli max_dup = 0;
    cout << "{";
    for(auto p : v) {
        cout << "{" <<  p.second << ", " << p.first << "}," << endl;
    }
    cout << "}" << endl;
    cout << "==============================" << endl;
    for(auto p : mp) {
        cout << p.first << ": " << p.second.size() << endl;
        if(p.second.size() > max_dup) {
            max_dup = p.second.size();
        }
        // if(p.second.size() > 1) {
        //     cout << "DUPLICATE FOR VALUE " << p.first << endl;
        // }
        // unordered_set<string> st;
        // for(string s : p.second) {
        //     // if(st.count(s)) {
        //     //     cout << "ACTUAL DUPLICATE: " << s << endl;
        //     // }
        //     auto temp = s.substr(s.size()-3, 3);
        //     // cout << "CHECKING " << temp << endl;
        //     if(st.find(temp) != st.end()) {
        //         cout << "ACTUAL DUPLICATE: " << temp << endl;
        //     }
        //     if(temp == "100" && st.find("001") != st.end()) {
        //         cout << "FOUND 100 AND 001 FOR VALUE " << p.first << endl;
        //     }
        //     if(temp == "001" && st.find("100") != st.end()) {
        //         cout << "FOUND 100 AND 001 FOR VALUE " << p.first << endl;
        //     }
        //     if(temp == "110" && st.find("011") != st.end()) {
        //         cout << "FOUND 110 AND 011 FOR VALUE " << p.first << endl;
        //     }
        //     if(temp == "011" && st.find("110") != st.end()) {
        //         cout << "FOUND 110 AND 011 FOR VALUE " << p.first << endl;
        //     }
        //     st.insert(temp);
        // }
        // cout << endl;
    }
    cout << "MAX DUPLICATES: " << max_dup << endl;
    // string tempp = "11010";
    // cout << cal("0" + tempp) << endl;
    // cout << cal("1" + tempp) << endl;
    cout << mp.size() << " VALUES" << endl;
    cout << v.size() << " STRINGS" << endl;
    unordered_map<lli, vector<string>> mpp;
    for(auto p : v) {
        mpp[p.second].push_back(p.first);
    }
    cout << "{";
    for(auto p : mpp) {
        cout << "{" << p.first << ", \"";
        for(auto s : p.second) {
            cout << s;
            if(s != p.second.back()) {
                cout << ", ";
            }
        }

        cout << "\"}," << endl;
    }
    cout << "}" << endl;
}