#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

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
    vector<string> grid(N, string(M, 'R'));
    bool ans = true;
    vector<pair<int, char>> colors = {{R, 'R'}, {G, 'G'}, {B, 'B'}};
    sort(colors.begin(), colors.end(), [](const pair<int, char>& a, const pair<int, char>& b) {
        return a.first > b.first; // Ordine decrescente
    });    

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            int index_color = 0;
            while ((index_color < 2) && ((colors[index_color].first == 0) ||
                    (i > 0 && grid[i-1][j] == colors[index_color].second) ||
                    (j > 0 && grid[i][j-1] == colors[index_color].second))) {
                index_color++;
            }
            grid[i][j] = colors[index_color].second;
            colors[index_color].first--;
        }
    }

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