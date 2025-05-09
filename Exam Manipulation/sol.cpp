#include <math.h>
#include <iostream>
#include <string>
#include <vector>
#include <climits>

using namespace std;

void bt(string temp, vector<string> &aString, int& res, int &k) {
    if(temp.size() == k) {
        int tempres = INT_MAX;
        for(auto &i: aString) {
            int tempp = 0;
            for(int j = 0; j < k; j++)  {
                if(i[j] == temp[j]) {
                    tempp++;
                }
            }
            tempres = min(tempres, tempp);
        }
        res = max(res, tempres);
    }
    else {
        bt(temp+'T', aString, res, k);
        bt(temp+'F', aString, res, k);
    }
}
int main() {
    int n, k;
    cin >> n >> k;
    int t = n;
    vector<string> aString;
    while(t--) {
        string s;
        cin >> s;
        aString.push_back(s);
    }
    int res = INT_MIN;
    bt("", aString, res, k);
    cout << res << endl;
}