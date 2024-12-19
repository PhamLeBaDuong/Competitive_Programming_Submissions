#include <iostream>
#include <string>
#include <regex>
#include <vector>
using namespace std;

int main() {
    long long res = 0;
    // int curr;
    while(true) {
        string s;
        cin >> s;
        if (s == "0000") {
            break;
        }
        
        // Regex to match mul() with 1-3 digit numbers and match with do() or don't()
        // regex mul_pattern(R"((mul\s*\(\s*(\d{1,3})\s*,\s*(\d{1,3})\s*\))|(do(n't)?\(\)))");
        regex mul_pattern(R"((mul\((\d{1,3}),(\d{1,3})\))|(do(n't)?\(\)))");
        
        // Find all matches
        sregex_iterator it(s.begin(), s.end(), mul_pattern);
        sregex_iterator end;
        
        // Collect and sum all multiplications
        // curr = 0;
        // bool cur = true;
        // string curr = "do()";
        while (it != end) {
            if((*it)[0] != "do()" && (*it)[0] != "don't()"){
                cout << (*it)[0] << endl;
                // cout << (*it)[1] << " " << (*it)[2] << endl;
                int first = stoi((*it)[2]);
                int second = stoi((*it)[3]);
                res += first * second;
            }
            else if ((*it)[0] == "don't()") {
                cout << (*it)[0] << endl;
                // curr = "don't()";
                while(it != end && (*it)[0] != "do()") {
                    ++it;
                }
            }
            ++it;
        }
    }
    cout << "Total result: " << res << endl;
    return 0;
}