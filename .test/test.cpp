#include <iostream>
#include <map>

using namespace std;


int main() {
    map<int, int> test_map;
    test_map[2] = 3;
    test_map[-1] = 2;
    test_map[-10] = 1;
    test_map[0] = 0;

    for (auto it = test_map.begin(); it != test_map.end(); it++) {
        cout << it->first << " " << it->second << endl;
    }
    
}