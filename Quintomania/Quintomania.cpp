#include <math.h>
#include <iostream>
#include <unordered_set>
#include <utility>
#include <vector>
#include <unordered_map>
using namespace std;
int main() {
    int testcases;
    cin >> testcases;
    for(int i = 0; i < testcases; i++)  {
        int n;
        bool breakk = false;
        cin >> n;
        int temp = -1;
        for(int ii = 0; ii < n; ii++) {
            int j;
            cin >> j;
            if(!breakk && temp != -1 && abs(j-temp) != 7 && abs(j-temp) != 5){
                cout << "NO" << endl;
                breakk = true;
            }
            temp = j;
        }
        if(!breakk) {
            cout << "YES" << endl;
        }
    }
}