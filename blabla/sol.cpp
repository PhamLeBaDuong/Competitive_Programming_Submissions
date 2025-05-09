#include <unordered_set>
#include <vector>
#include <iostream>

using namespace std;

int bt(unordered_set<int> &st, vector<int> curr, int i) {
    if(i > 31) {
        return 0;
    }
    int res = 0;
    for(int j = i; j <= 31; j++) {
        auto temp = curr;
        for(auto &t : curr) {
            if(st.find(t+j) == st.end()) {
                temp.push_back(j);
                res = max(res, 1 + bt(st, temp, j+1));
            }
        }
        res = max(res, bt(st, curr, j+1));
    }
    return res;
}

int main() {
    unordered_set<int> st;
    st.insert(4);
    st.insert(9);
    st.insert(16);
    st.insert(25);
    st.insert(36);
    st.insert(49);
    cout << bt(st, {}, 1);
}