#include <climits>
#include <cstdio>
#include <math.h>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<vector<int>> arr;
    vector<vector<int>> a(2);
    int t = n;
    for(int i = 0; i < n; i++){
        char s;
        cin >> s;
        vector<int> temp(2);
        cin >> temp[0] >> temp[1];
        arr.push_back(temp);
        if(s == 'N') {
            a[0].push_back(i);
        }
        else {
            a[1].push_back(i);
        }
    }
    sort(a[0].begin(), a[0].end(), [arr](int aa, int bb){
        return arr[aa][0] < arr[bb][0];
    });
    sort(a[1].begin(), a[1].end(), [arr](int aa, int bb){
        return arr[aa][1] < arr[bb][1];
    });
    // for(auto &i : a) {
    //     for(auto &j : i) {
    //         // cout << j << " ";
        
    //         cout << arr[j][0] << ":" << arr[j][1] << " ";
    //     }
    //     cout << endl;
    // }
    // return 0;
    vector<int> res(n,1);
    for(int i = 0; i < a[0].size(); i++) {
        for(int j = 0; j < a[1].size(); j++) {
            if(arr[a[0][i]][1] > arr[a[1][j]][1] || arr[a[0][i]][0] < arr[a[1][j]][0] || res[a[1][j]] != 1) {
                continue;
            }
            if(arr[a[0][i]][0] - arr[a[1][j]][0] > arr[a[1][j]][1] - arr[a[0][i]][1]) {
                // cout << "wtf";
                res[a[1][j]] = arr[a[0][i]][0] - arr[a[1][j]][0];
            }
            else if(arr[a[0][i]][0] - arr[a[1][j]][0] < arr[a[1][j]][1] - arr[a[0][i]][1]) {
                // cout << "wtf";
                res[a[0][i]] = arr[a[1][j]][1] - arr[a[0][i]][1];
                break;
            }
        }
        // if(res[a[0][i]] == 1) {
        //     res[a[0][i]] = -1;
        // }
    }
    for(auto &i : res) {
        cout << (i == 1 ? "Infinity" : to_string(i)) << endl;
    }
    // for(int j = 0; j < a[1].size(); j++) {
    //     if(res[a[1][j]] == 1) {
    //         res[a[1][j]] = -1;
    //     }
    //     for(int i = 0; i < a[0].size(); i++) {
    //         if(arr[a[0][i]][1] > arr[a[1][j]][1] || arr[a[0][i]][0] < arr[a[1][j]][0] || res[a[0][i]] == 0) {
    //             continue;
    //         }
    //         if(arr[a[0][i]][0] - arr[a[1][j]][0] > arr[a[0][i]][1] - arr[a[1][j]][1]) {
    //             res[a[1][j]] = 0;
    //         }
    //         else if(arr[a[0][i]][0] - arr[a[1][j]][0] < arr[a[0][i]][1] - arr[a[1][j]][1]) {
    //             res[a[0][i]] = arr[a[0][i]][0] - arr[a[1][j]][0];
    //         }
    //     }
    // }
}