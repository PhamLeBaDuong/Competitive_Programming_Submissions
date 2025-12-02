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
#include <random>
#include <bits/chrono.h>
using namespace std;
typedef pair<pair<int, int>, int> pipii;
typedef pair<int, int> pii;
typedef long long lli;

unordered_map<int, int> mp;
unordered_map<string, lli> mp2;
string test_case;

lli cal(string s) {
    vector<int> suf(s.size(), 0);
    suf[s.size()-1] = (s[s.size()-1] - '0');
    for(int i = s.size()-2; i >= 0; i--) {
        suf[i] = suf[i+1] + (s[i] - '0');
    }
    suf.push_back(0);

    lli res = 0;
    for(int i = 0; i < s.size(); i++) {
        for(int j = s.size()-1; j >= i; j--) {
            res += suf[i] - suf[j+1];
        }
    }
    return res;
}

lli sum_of_prefixes(string s) {
    lli total = 0;
    lli running = 0;
    for(char c : s) {
        running += (c - '0');
        total += running;
    }
    return total;
}

string check(string res, unordered_map<int, string> &mp5, unordered_map<int, string> &mp4, vector<lli> &queries) {
    string temp = res;
    int input;

    for(int i = 0; i < queries.size()-1; i++) {
        input = queries[i];
        input -= cal(temp) + sum_of_prefixes(temp)*5;
        if(mp5.find(input) == mp5.end()) {
            return "";
        }
        temp = mp5[input] + res[0];
        res = mp5[input] + res;
    }
    input = queries[queries.size()-1];
    temp.pop_back();
    input -= cal(temp) + sum_of_prefixes(temp)*4;
    if(mp4.find(input) == mp4.end()) {
        return "";
    }
    res = mp4[input] + res;
    return res;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    std::mt19937 generator(std::chrono::system_clock::now().time_since_epoch().count());
    
    string res;
    unordered_map<int, vector<string>> mp6 = {{56, {"111111"}},
                                            {50, {"011111", "111110"}},
                                            {46, {"101111", "111101"}},
                                            {44, {"111011", "011110", "110111"}},
                                            {40, {"011101", "111100", "001111", "101110"}},
                                            {38, {"110110", "111010", "011011", "010111"}},
                                            {36, {"101101"}},
                                            {34, {"100111", "111001", "001110", "011100", "110101", "101011"}},
                                            {0, {"000000"}},
                                            {26, {"110010", "010011"}},
                                            {6, {"000001", "100000"}},
                                            {32, {"011010", "010110", "110011"}},
                                            {10, {"000010", "010000"}},
                                            {12, {"100001", "001000", "000100"}},
                                            {16, {"000011", "100010", "010001", "110000"}},
                                            {18, {"000101", "101000", "001001", "100100"}},
                                            {20, {"010010"}},
                                            {22, {"011000", "110001", "100011", "001010", "010100", "000110"}},
                                            {24, {"101001", "001100", "100101"}},
                                            {28, {"010101", "001011", "110100", "100110", "111000", "011001", "101010", "000111"}},
                                            {30, {"101100", "001101"}},
                                        };
                                        
    unordered_map<int, string> mp5 = {{114, "01111"},
                                    {55, "01001"},
                                    {47, "01100"},
                                    {43, "10010"},
                                    {38, "10100"},
                                    {67, "00011"},
                                    {93, "11101"},
                                    {32, "00010"},
                                    {90, "11110"},
                                    {31, "11000"},
                                    {27, "00100"},
                                    {105, "10111"},
                                    {46, "10001"},
                                    {78, "10011"},
                                    {98, "11011"},
                                    {52, "01010"},
                                    {58, "11100"},
                                    {87, "01011"},
                                    {0, "00000"},
                                    {59, "00110"},
                                    {62, "00101"},
                                    {63, "11010"},
                                    {125, "11111"},
                                    {66, "11001"},
                                    {11, "10000"},
                                    {70, "10110"},
                                    {73, "10101"},
                                    {20, "01000"},
                                    {79, "01110"},  
                                    {82, "01101"},
                                    {35, "00001"},
                                    {94, "00111"},
                                    };
    unordered_map<int, string> mp4 = {{70, "1111"},
                                    {61, "0111"},
                                    {0, "0000"},
                                    {9, "1000"},
                                    {21, "0010"},
                                    {24, "0001"},
                                    {37, "0110"},
                                    {54, "1011"},
                                    {25, "1100"},
                                    {30, "1010"},
                                    {33, "1001"},
                                    {46, "1110"},
                                    {40, "0101"},
                                    {16, "0100"},
                                    {45, "0011"},
                                    {49, "1101"},
                                    };
    int input;
    cout << "? 2020 2025" << endl;
    cout.flush();
    cin >> input;
    int input6 = input;
    std::uniform_int_distribution<int> distribution(0, mp6[input].size() - 1);
    vector<lli> queries;

    for(int i = 2015; i >= 1; i-=5) {
        cout << "? " << i << " " << i+10 << endl;
        cout.flush();
        cin >> input;
        queries.push_back(input);
    }
    cout << "? 1 9" << endl;
    cout.flush();
    cin >> input;
    queries.push_back(input);
    unordered_set<int> visited;
    while(visited.size() < mp6[input6].size()) {
        int i = distribution(generator);
        if(visited.find(i) != visited.end()) continue;
        visited.insert(i);
        auto temp = check(mp6[input6][i], mp5, mp4, queries);
        if(temp != "") {
            res = temp;
            break;
        }
    }
    cout << "! " << res << endl;
}