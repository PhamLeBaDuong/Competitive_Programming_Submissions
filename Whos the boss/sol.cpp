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

using namespace std;

int main() {
    int m, q;
    cin >> m >> q;
    unordered_map<int, int> im_boss;
    unordered_map<int, int> sub_count;
    vector<vector<int>> employees(m, vector<int>(3));
    for(int i = 0; i < m; i++) {
        cin >> employees[i][0] >> employees[i][1] >> employees[i][2];
    }
    sort(employees.begin(), employees.end(), [](const vector<int>& a, const vector<int>& b) {
        return a[1] == b[1] ? a[2] < a[2] : a[1] < b[1];
    });
    stack<vector<int>> st;
    for(int i = 0; i < m; i++) {
        while(!st.empty() && st.top()[2] <= employees[i][2]) {
            im_boss[st.top()[0]] = employees[i][0];
            sub_count[employees[i][0]] += 1 + sub_count[st.top()[0]];
            st.pop();
        }
        st.push(employees[i]);
    }
    while(q--) {
        int emp;
        cin >> emp;
        cout << im_boss[emp] << " " << sub_count[emp] << "\n";
    }
}