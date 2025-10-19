#include <bits/stdc++.h>

using namespace std;

int main()
{
    ifstream cin("input.txt");
    int n;
    cin >> n;
    vector<vector<int>> grid(n, vector<int>(n));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> grid[i][j];

    int count = 0;
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - 1; j++)
        {
            for (int k = i + 1; k < n; k++)
            {
                if ((grid[i][j] > grid[k][j]) == (grid[i][k] > grid[k][k]))
                {
                    count++;
                    cout << grid[i][j] << ' ' << grid[k][j] << ' ' << grid[i][k] << ' ' << grid[k][k] << endl;
                }
            }
        }
    }
    cout << count << endl;
}