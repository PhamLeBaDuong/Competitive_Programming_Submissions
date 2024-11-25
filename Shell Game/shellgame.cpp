#include <math.h>
#include <iostream>
#include <string>
#include <utility>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <queue>
using namespace std;
int main() {

	freopen("shell.in", "r", stdin);
	// the following line creates/overwrites the output file
	freopen("shell.out", "w", stdout);
    int n;
    cin >> n;
    vector<vector<int>> swaps;
    vector<int> guesses;
    int maxx = INT_MIN;
    while(n--) {
        int a, b, g;
        cin >> a >> b >> g;
        swaps.push_back({a, b});
        guesses.push_back(g);        
    }
    for(int i = 1; i <= 3; i++) {
        auto curr = i;
        int res = 0;
        for(int j = 0; j < swaps.size(); j++) {
            if(curr == swaps[j][0] || curr == swaps[j][1])
            {
                curr = swaps[j][0] + swaps[j][1]-curr;
            }
            if(curr == guesses[j])
            {
                res++;
            }
            
        }
        maxx = max(maxx, res);
    }
    cout << maxx << endl;
}
    