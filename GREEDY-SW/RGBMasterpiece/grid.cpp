#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

bool isValidGrid(const vector<string> &grid, int N, int M)
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            if ((j > 0 && grid[i][j] == grid[i][j - 1]) || (i > 0 && grid[i][j] == grid[i - 1][j]))
            {
                return false;
            }
        }
    }
    return true;
}

int main()
{
    ifstream cin("input.txt");
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
    vector<pair<int, char>> colors = {{R, 'R'}, {G, 'G'}, {B, 'B'}};
    sort(colors.begin(), colors.end(), [](const pair<int, char> &a, const pair<int, char> &b)
         {
             return a.first > b.first; // Ordine decrescente
         });

    for (int k = 0; k < 2; k++)
    {
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < M; j++)
            {
                if ((i + j) % 2 == k)
                {
                    int index_color = 0;
                    while (colors[index_color].first == 0)
                    {
                        index_color++;
                    }
                    grid[i][j] = colors[index_color].second;
                    colors[index_color].first--;
                }
            }
        }
    }

    if (isValidGrid(grid, N, M))
    {
        cout << "YES" << endl;
        for (int i = 0; i < N; ++i)
            cout << grid[i] << endl;
        return 0;
    }
    vector<string> grid2(N, string(M, 'R'));
    vector<pair<int, char>> colors2 = {{R, 'R'}, {G, 'G'}, {B, 'B'}};
    for (int k = 0; k < 2; k++)
    {
        for (int j = M - 1; j >= 0; j--)
        {
            for (int i = N - 1; i >= 0; i--)
            {
                if ((i + j) % 2 != k)
                {
                    int index_color = 0;
                    while (colors2[index_color].first == 0)
                    {
                        index_color++;
                    }
                    grid2[i][j] = colors2[index_color].second;
                    colors2[index_color].first--;
                }
            }
        }
    }

    cout << "YES" << endl;
    for (int i = 0; i < N; ++i)
        cout << grid2[i] << endl;
    return 0;
}
