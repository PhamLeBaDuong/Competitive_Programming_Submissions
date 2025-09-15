#include <math.h>
#include <iostream>
#include <unordered_set>
#include <utility>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <queue>
using namespace std;
typedef long long int lli; 
int main() {
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        lli res = 0;
        vector<pair<int, int>> v(n);
        auto cmp1 = [v](int &a, int &b) {
            return v[a].second < v[b].second;
        };
        // auto cmp2 = [v](int &a, int &b) {
        // auto cmp2 = [v](pair<int, int> &a, pair<int, int> &b) {
            // return v[a].first > v[b].first;
        // };
        priority_queue<int, vector<int>, decltype(cmp1)> pq1(cmp1);
        // priority_queue<int, vector<int>, decltype(cmp2)> pq2(cmp2);
        // priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(cmp2)> pq2(cmp2);
        for(int i = 0; i < n; i++) {
            int a, b;
            cin >> a >> b;
            v[i] = {a, b};
            res += b-a;
            // pq1.push({a, b});
            // pq2.push({a, b});
        }
        sort(v.begin(), v.end());
        for(int i = 0; i < n; i++) {
            pq1.push(i);
            // pq2.push(i);
        }
        int i = 0;
        int count = 0;
        while(n-count >= 1) {
            while(v[i].first == -1) {
                i++;
            }
            while(!pq1.empty() && v[pq1.top()].first == -1) {
                pq1.pop();
            }
            if(pq1.top() == i) {
                res += v[pq1.top()].second - v[i].first;
                v[i].first = -1;
                count++;
                pq1.pop();
            }
            else {
                res += v[pq1.top()].second - v[i].first;
                v[i].first = -1;
                v[pq1.top()].first = -1;
                count += 2;
                pq1.pop();
                
            }
            // if(pq1.top() == pq2.top()) {
            //     res += (v[pq1.top()].second - v[pq1.top()].first) * 1;
            //     pq1.pop();
            //     pq2.pop();
            //     count++;
            // }
            // else {
            //     res += v[pq1.top()].second - v[pq2.top()].first;
            //     // res += v[pq1.top()].second - v[pq1.top()].first + v[pq2.top()].second - v[pq2.top()].first + v[pq1.top()].second - v[pq2.top()].first;
            //     pq1.pop();
            //     pq2.pop();
            //     count += 2;
            // }
            // res += max(pq1.top().first, pq1.top().second) - min(pq2.top().first, pq2.top().second);
        }
        // if(n - count == 1) {
        //     res += v[pq1.top()].second - v[pq1.top()].first;
        // }
        cout << res << endl;
        cout << endl;

    }
}

// #include <bits/stdc++.h>
// using namespace std;
// using int64 = long long;
// struct Seg { int64 l, r; int idx; };

// int main() {
//     ios::sync_with_stdio(false);
//     cin.tie(nullptr);
//     int t;
//     if (!(cin >> t)) return 0;
//     while (t--) {
//         int n; cin >> n;
//         vector<Seg> a(n);
//         int64 origSum = 0;
//         for (int i = 0; i < n; ++i) {
//             cin >> a[i].l >> a[i].r;
//             a[i].idx = i;
//             origSum += (a[i].r - a[i].l);
//         }

//         // sort indices by l ascending
//         vector<Seg> byL = a;
//         sort(byL.begin(), byL.end(), [](const Seg &A, const Seg &B){
//             if (A.l != B.l) return A.l < B.l;
//             return A.r < B.r;
//         });

//         // max-heap by r
//         priority_queue<pair<int64,int>> pq; // (r, idx)
//         for (int i = 0; i < n; ++i) pq.push({a[i].r, a[i].idx});

//         vector<char> used(n, 0);
//         int ptr = 0;
//         int pairs = n / 2;
//         int64 extra = 0;

//         for (int k = 0; k < pairs; ++k) {
//             // find next unused left (smallest l)
//             while (ptr < n && used[byL[ptr].idx]) ++ptr;
//             // ptr must be valid
//             Seg left = byL[ptr];
//             used[left.idx] = 1; // mark left as used so we won't pick it as right

//             // pick largest r among unused
//             while (!pq.empty() && used[pq.top().second]) pq.pop();
//             auto top = pq.top(); pq.pop();
//             int ridx = top.second;
//             Seg right = a[ridx];
//             used[ridx] = 1;

//             int64 gain = max(left.r, right.r) - min(left.l, right.l);
//             extra += gain;
//             // continue to next pair
//         }

//         cout << (origSum + extra) << '\n' << endl;
//     }
//     return 0;
// }
