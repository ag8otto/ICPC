#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    ifstream cin("input0.txt");
    ofstream cout("output.txt");

    int N, M, R, G, B;
    cin >> N >> M >> R >> G >> B;
    int lim;
    if((N & 1) == 0) lim = M * N/2;
    else if((M & 1) == 0) lim = N * M/2;
    else lim = N *((M+1)/2) - M/2;
    int peak = max({R, B, G});
    if(peak > lim){
        cout << "NO" << endl;
        return 0;
    }
    vector<string> grid(N, string(M, 'R'));
    bool ans = true;

    vector<pair<int, char>> colors = {{R, 'R'}, {G, 'G'}, {B, 'B'}};
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            auto it = find_if(colors.begin(), colors.end(), [&](const pair<int, char>& p) {
                return p.first == 0;
            });
            if (it != colors.end()) colors.erase(it);
            grid[i][j] = colors[(i+j)%colors.size()].second;
        }
    }
    if (ans) {
        cout << "YES" << endl;
        for (int i = 0; i < N; ++i)
            cout << grid[i] << endl;
    } else {
        cout << "NO" << endl;
    }

    return 0;
}