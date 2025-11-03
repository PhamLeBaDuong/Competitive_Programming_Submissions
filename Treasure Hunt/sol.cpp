#include <math.h>
#include <iostream>
#include <unordered_set>
#include <utility>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <queue>
using namespace std;
int main()
{
    cin.tie(nullptr);
    std::ios::sync_with_stdio(false);
    int input = 0;
    cout << "? 4 2" << endl;
    cin >> input;
    if (input == 1)
    {
        cout << "? 4 3"<< endl;
        cin >> input;
        if (input == 1)
        {
            cout << "? 3 2"<< endl;
            cin >> input;
            if (input == 1)
            {
                cout << "! 3 2"<< endl;
                return 0;
            }
            cout << "! 4 2"<< endl;
            return 0;
        }
        else
        {
            cout << "? 3 2"<< endl;
            cin >> input;
            if (input == 1)
            {
                cout << "! 3 1"<< endl;
                return 0;
            }
            cout << "! 4 1"<< endl;
            return 0;
        }
    }
    else
    {
        cout << "? 4 4"<< endl;
        cin >> input;
        if (input == 1)
        {
            cout << "? 4 5"<< endl;
            cin >> input;
            if (input == 1)
            {
                cout << "? 3 4"<< endl;
                cin >> input;
                if (input == 1)
                {
                    cout << "! 3 4"<< endl;
                    return 0;
                }
                cout << "! 4 4"<< endl;
                return 0;
            }
            else
            {
                cout << "? 3 4"<< endl;
                cin >> input;
                if (input == 1)
                {
                    cout << "! 3 3"<< endl;
                    return 0;
                }
                cout << "! 4 3"<< endl;
                return 0;
            }
        }
        else
        {
            cout << "? 2 3"<< endl;
            cin >> input;
            if (input == 1)
            {
                cout << "? 2 4"<< endl;
                cin >> input;
                if (input == 1)
                {
                    cout << "? 1 3"<< endl;
                    cin >> input;
                    if (input == 1)
                    {
                        cout << "! 1 3"<< endl;
                        return 0;
                    }
                    cout << "! 2 3"<< endl;
                    return 0;
                }
                else
                {
                    cout << "? 1 3"<< endl;
                    cin >> input;
                    if (input == 1)
                    {
                        cout << "! 1 2"<< endl;
                        return 0;
                    }
                    cout << "! 2 2"<< endl;
                    return 0;
                }
            }
            else
            {
                cout << "? 2 2"<< endl;
                cin >> input;
                if (input == 1)
                {
                    cout << "? 1 2"<< endl;
                    cin >> input;
                    if (input == 1)
                    {
                        cout << "! 1 1"<< endl;
                        return 0;
                    }
                    cout << "! 2 1"<< endl;
                    return 0;
                }
                else
                {
                    cout << "? 1 4"<< endl;
                    cin >> input;
                    if (input == 1)
                    {
                        cout << "! 1 4"<< endl;
                        return 0;
                    }
                    cout << "! 2 4"<< endl;
                    return 0;
                }
            }
        }
    }
}