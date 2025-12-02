#include <bits/stdc++.h>
using namespace std;
typedef long long lli;

lli cal(const string& s) {
    int n = s.size();
    vector<int> suf(n + 1, 0);
    for(int i = n - 1; i >= 0; i--) {
        suf[i] = suf[i+1] + (s[i] - '0');
    }
    
    lli res = 0;
    for(int i = 0; i < n; i++) {
        for(int j = i; j < n; j++) {
            res += suf[i] - suf[j+1];
        }
    }
    return res;
}

lli sum_of_prefixes(const string& s) {
    lli total = 0;
    lli running = 0;
    for(char c : s) {
        running += (c - '0');
        total += running;
    }
    return total;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
    
    unordered_map<int, vector<string>> mp6 = {
        {56, {"111111"}}, {50, {"011111", "111110"}}, {46, {"101111", "111101"}},
        {44, {"111011", "011110", "110111"}}, {40, {"011101", "111100", "001111", "101110"}},
        {38, {"110110", "111010", "011011", "010111"}}, {36, {"101101"}},
        {34, {"100111", "111001", "001110", "011100", "110101", "101011"}},
        {0, {"000000"}}, {26, {"110010", "010011"}}, {6, {"000001", "100000"}},
        {32, {"011010", "010110", "110011"}}, {10, {"000010", "010000"}},
        {12, {"100001", "001000", "000100"}}, {16, {"000011", "100010", "010001", "110000"}},
        {18, {"000101", "101000", "001001", "100100"}}, {20, {"010010"}},
        {22, {"011000", "110001", "100011", "001010", "010100", "000110"}},
        {24, {"101001", "001100", "100101"}},
        {28, {"010101", "001011", "110100", "100110", "111000", "011001", "101010", "000111"}},
        {30, {"101100", "001101"}}
    };

    unordered_map<int, string> mp5 = {
        {114, "01111"}, {55, "01001"}, {47, "01100"}, {43, "10010"}, {38, "10100"},
        {67, "00011"}, {93, "11101"}, {32, "00010"}, {90, "11110"}, {31, "11000"},
        {27, "00100"}, {105, "10111"}, {46, "10001"}, {78, "10011"}, {98, "11011"},
        {52, "01010"}, {58, "11100"}, {87, "01011"}, {0, "00000"}, {59, "00110"},
        {62, "00101"}, {63, "11010"}, {125, "11111"}, {66, "11001"}, {11, "10000"},
        {70, "10110"}, {73, "10101"}, {20, "01000"}, {79, "01110"}, {82, "01101"},
        {35, "00001"}, {94, "00111"}
    };
    
    unordered_map<int, string> mp4 = {
        {70, "1111"}, {61, "0111"}, {0, "0000"}, {9, "1000"}, {21, "0010"},
        {24, "0001"}, {37, "0110"}, {54, "1011"}, {25, "1100"}, {30, "1010"},
        {33, "1001"}, {46, "1110"}, {40, "0101"}, {16, "0100"}, {45, "0011"},
        {49, "1101"}
    };
    
    // Query last 6 bits
    cout << "? 2020 2025" << endl;
    int input;
    cin >> input;
    if(input == -1) return 0;
    
    uniform_int_distribution<int> dist(0, mp6[input].size() - 1);
    string res = mp6[input][dist(rng)];
    
    // Precompute for first 6 bits
    lli cal_6 = cal(res);
    lli prefix_sum_6 = sum_of_prefixes(res);
    
    // Decode in chunks of 5
    for(int i = 2015; i >= 1; i -= 5) {
        cout << "? " << i << " " << (i + 10) << endl;
        cin >> input;
        if(input == -1) return 0;
        
        // Use precomputed values instead of recalculating
        input -= cal_6 + prefix_sum_6 * 5;
        
        string new_chunk = mp5[input];
        res = new_chunk + res;
        
        // Update precomputed values for next iteration
        // Now we have 11 bits, but we only need first 6 for next query
        string first_6 = res.substr(0, 6);
        cal_6 = cal(first_6);
        prefix_sum_6 = sum_of_prefixes(first_6);
    }
    
    // Final query for first 4 bits
    cout << "? 1 9" << endl;
    cin >> input;
    if(input == -1) return 0;
    
    string first_5 = res.substr(0, 5);
    lli cal_5 = cal(first_5);
    lli prefix_sum_5 = sum_of_prefixes(first_5);
    input -= cal_5 + prefix_sum_5 * 4;
    
    res = mp4[input] + res;
    
    cout << "! " << res << endl;
    
    return 0;
}