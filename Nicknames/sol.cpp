#include <math.h>
#include <iostream>
#include <string>
#include <utility>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <queue>
#include <unordered_set>
#include <climits>
using namespace std;
typedef pair<pair<int, int>, int> pipii;
typedef pair<int, int> pii;
typedef long long int lli;

class TrieNode {
public:
    // TrieNode* children[26];
    vector<TrieNode*> children;
    int isPre;
    TrieNode() {
        isPre = 0;
        children = vector<TrieNode*>(26, nullptr);
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    TrieNode* root = new TrieNode();
    int n;
    cin >> n;
    // scanf("%d", &n);
    for(int i = 0; i < n; i++) {
        string s;
        cin >> s;
        // scanf("%s", &s);
        // cout << s << " " << n << endl;
        TrieNode* curr = root;
        for(char &j : s) {
            if(curr->children[j - 'a'] == nullptr) {
                // cout << "wth" << endl;
                curr->children[j - 'a'] = new TrieNode();
            }
            curr = curr->children[j - 'a'];
            curr->isPre++;
        }
        // cout << curr->isEnd << endl;
        // curr->isEnd++;
    }
    cin >> n;
    // scanf("%d", &n);
    vector<int> res(n);
    for(int i = 0; i < n; i++) {
        string s;
        cin >> s;
        // scanf("%s", &s);
        TrieNode* curr = root;
        
        for(auto &j : s) {
            if(curr->children[j - 'a'] == nullptr) {
                // cout << "NO" << endl;
                break;
            }
            curr = curr->children[j - 'a'];
        }
        res[i] = curr ? curr->isPre : 0;
    }
    for(auto &i : res) {
        cout << i << endl;
        // printf("%d\n", i);
    }
}