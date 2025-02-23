// NOTE: it is recommended to use this even if you don't understand the following code.

#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

void printGrid(vector<string> grid)
{
    for (long unsigned int i = 0; i < grid.size(); i++)
    {
        for (long unsigned int j = 0; j < grid[i].size(); j++)
        {
            cout << grid[i][j] << ' ';
        }
        cout << endl;
    }
}
bool solve_matrix(vector<string> &grid, vector<pair<int, char>> colors, int i, int j)
{
    if (i == (int)grid.size())
    {
        return true;
    }
    else if (((i == 0) ? false : grid[i - 1][j] == grid[i][j]) || ((j == 0) ? false : grid[i][j - 1] == grid[i][j]))
    {
        return false;
    }
    else
    { 
        int index = i + j;
        while (colors[(index) % 3].first == 0)
        {
            index++;
        }
        bool res;
        grid[i][j] = colors[(i + j) % 3].second;
        colors[(i + j) % 3].first--;
        printGrid(grid);
        cout << endl
             << endl;
        if (j == (int)grid[i].size() - 1)
            res = solve_matrix(grid, colors, i + 1, 0);
        else
            res = solve_matrix(grid, colors, i, j + 1);
    }
}
int main()
{
    ifstream cin("input0.txt");
    ofstream cout("output.txt");

    int N, M, R, G, B;
    cin >> N >> M >> R >> G >> B;
    int lim;
    if ((N & 1) == 0 || (M & 1) == 0)
        lim = (N * M) / 2;
    else
        lim = (N * M) / 2 + 1;
    int peak = max({R, B, G});
    if (peak > lim)
    {
        cout << "NO" << endl;
        return 0;
    }
    vector<string> grid(N, string(M, '_'));
    bool ans = true;
    vector<pair<int, char>> colors = {{R, 'R'}, {G, 'G'}, {B, 'B'}};
    solve_matrix(grid, colors, 0, 0);
    if (ans)
    {
        cout << "YES" << endl;
        for (int i = 0; i < N; ++i)
            cout << grid[i] << endl;
    }
    else
    {
        cout << "NO" << endl;
    }

    return 0;
}
