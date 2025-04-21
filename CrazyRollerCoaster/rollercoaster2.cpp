#include <fstream>
#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>
#include <cmath>
#include <climits>
using namespace std;

int main()
{
    ifstream cin("input0.txt");
    int N;
    vector<int> H;
    cin >> N;
    H.resize(N);

    for (int i = 0; i < N; i++)
        cin >> H[i];

    int Hmax = *max_element(H.begin(), H.end());
    vector<vector<int>> Cost_Grid(N, vector<int>(Hmax + 1, -1));
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < Hmax + 1; j++)
        {
            Cost_Grid[i][j] = pow(H[i] - j, 2);
            cout << Cost_Grid[i][j] << ' ';
        }
        cout << endl;
    }
    cout << endl;
    vector<int> up(Hmax + 1);
    for (int i = 0; i < Hmax; i++)
    {
        int mini = INT_MAX;
        for (int j = i+1; j < Hmax + 1; j++)
        {
            up[i] = min(mini, Cost_Grid[0][i] + Cost_Grid[1][j]);
            mini = up[i];
        }
        cout<< up[i] << ' ';
    }

    return 0;
}