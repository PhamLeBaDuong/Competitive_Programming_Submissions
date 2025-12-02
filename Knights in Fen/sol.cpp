#include <climits>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <string>
#include <thread>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>
#include <set>

using namespace std;

void bt(int i, int j, int count, vector<vector<int>> &dirs, vector<string> &target, vector<string> &mat, int prev, int &res)
{
    if (mat == target)
    {
        res = min(res, count);
        return;
    }
    if (count >= min(res, 10))
    {
        return;
    }
    int index = 0;
    for (auto &dir : dirs)
    {
        int ii = i + dir[0];
        int jj = j + dir[1];
        if (ii < 0 || jj < 0 || ii >= 5 || jj >= 5) {
            continue;
        }
        swap(mat[i][j], mat[ii][jj]);
        bt(ii, jj, count + 1, dirs, target, mat, (index + 4) % 8, res);
        swap(mat[i][j], mat[ii][jj]);
        index++;
    }
}

int main()
{
    string tempp;
    getline(cin, tempp);
    int t;
    t = stoi(tempp);

    vector<vector<int>> dirs = {{-2, -1}, {-1, -2}, {1, -2}, {2, -1}, {2, 1}, {1, 2}, {-1, 2}, {-2, 1}};
    vector<string> target = {"11111",
                             "01111",
                             "00 11",
                             "00001",
                             "00000"};
    vector<string> board(5);
    while (t--)
    {
        for (int i = 0; i < 5; i++)
        {
            string temp;
            getline(cin, temp);
            if (i == -1)
            {
                continue;
            }
            board[i] = temp;
        }
        bool flag = false;
        int res = INT_MAX;
        set<vector<string>> st;
        for (int i = 0; i < 5; i++)
        {
            for (int j = 0; j < 5; j++)
            {
                if (board[i][j] == ' ')
                {
                    bt(i, j, 0, dirs, target, board, -1, res);
                    if (res == INT_MAX) 
                    {
                        cout << "Unsolvable in less than 11 move(s).\n";
                    }
                    else
                    {
                        cout << "Solvable in " << res << " move(s).\n";
                    }
                    flag = true;
                    break;
                }
            }
            if (flag)
            {
                break;
            }
        }
    }
}