#include <math.h>
#include <iostream>
#include <string>
#include <utility>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <queue>
#include <unordered_set>
using namespace std;
int main() {
    int t;
    cin >> t;
    while(t--) {
        int k;
        cin >> k;
        unordered_map<int, int> st;
        int count = 0;
        while(k--) {
            int a;
            cin >> a;
            st[a]++;
            count++;
        }
        count -= 2;
        for(auto i : st)
        {
            if(count % i.first == 0 && st.find(count/i.first) != st.end())
            {
                if(i.first == count/i.first && i.second == 1)
                {
                    continue;
                }
                cout << i.first << " " << count/i.first << endl;
                break;
            }
        }

    }
}