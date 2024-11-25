#include <math.h>
#include <iostream>
#include <unordered_set>
#include <utility>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <cmath>
using namespace std;
int main() {
    int n, x;
    cin >> n >> x;
    vector<vector<double>> arr(n);
    for(int i = 0; i < n; i++) {
        cin >> arr[i][0] >> arr[i][1] >> arr[i][2];
    }
    vector<vector<double>> list1;
    for(int i = 0; i < n; i++) {
        list1.push_back({arr[i][0], arr[i][1], atan((arr[i][1]) / (arr[i][0]-8))});
    }
    sort(list1.begin(), list1.end(), [] (vector<double> a, vector<double> b) {
        return a[2] < b[2];
    });
    vector<vector<double>> list2;
    for(int i = 0; i < n; i++) {
        list2.push_back({arr[i][0], arr[i][1], atan((arr[i][1]) / (arr[i][0]-8))});
    }
    sort(list2.begin(), list2.end(), [] (vector<double> a, vector<double> b) {
        return a[2] < b[2];
    });


    
    // for(int i = 0; i < n; i++) {
    //     for(int j = 0; j < n; j++) {
            
    //         if(j != i) {
    //             if(arr[j][1] < arr[i][1]) {
    //                 if(arr[j][0] > arr[i][0]) {
    //                     double a = arr
    //                 }
    //             }
    //         }
    //     }
    // }

}