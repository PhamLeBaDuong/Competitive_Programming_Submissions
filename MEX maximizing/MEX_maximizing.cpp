#include <iostream>
#include <utility>
#include <queue>
#include <unordered_set>
using namespace std;
class Compare
{
    public:
        bool operator () (pair<int, int> below, pair<int, int> above)
        {
            return below.second <= above.second;
        }
};
int main() {
    int q,x;
    cin >> q >> x;
    int originalMEX = 0;
    //priority_queue<pair<int, int>, vector<pair<int, int>>, Compare> pq;
    priority_queue<int, vector<int>, less<int>> pqMin;
    priority_queue<int, vector<int>, greater<int>> pqMax;
    unordered_set<int> visited;
    for(int ii = 1; ii <= q; ii++) {
        int j;
        cin >> j;
        if(j == originalMEX) {
            originalMEX = j+1;
            pqMin.push(j);
            pqMax.push(j);
            visited.insert(j);
        }
        auto tempMex = originalMEX;
        auto tempVisited = visited;
        while(pqMin.top() < tempMex && pqMax.top() > tempMex) {
            if(pqMin.top() < tempMex) {
                auto temp1 = pqMin.top();
                pqMin.pop();
                if(pqMin.top() % x == tempMex % x) {
                    pqMin.push(tempMex);
                    tempVisited.insert(tempMex);
                    tempMex++;
                    while(tempVisited.find(tempMex) != tempVisited.end()) {
                        tempMex++;
                    }
                }
                tempVisited.erase(temp1);
            }
            if(pqMax.top() > tempMex) {
                auto temp1 = pqMax.top();
                pqMax.pop();
                if(pqMax.top() % x == tempMex % x) {
                    pqMax.push(tempMex);
                    tempVisited.insert(tempMex);
                    tempMex++;
                    while(tempVisited.find(tempMex) != tempVisited.end()) {
                        tempMex++;
                    }
                }
                tempVisited.erase(temp1);
            }
        }
        cout << tempMex << endl;
    }
}
// int main() {
//     int q,x;
//     cin >> q >> x;
//     int originalMEX = 0;
//     for(int ii = 1; ii <= q; ii++) {        
//         int j;
//         cin >> j;
//         if(j == originalMEX) {
//             originalMEX++;
//         }

//     }
// }
