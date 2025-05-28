#include <iostream>
#include <fstream>
#include <vector>
#include <cassert>
#include <algorithm>
#include <numeric>
#include <cmath>
#include <climits>
using namespace std;

int main()
{
    ifstream cin("input0.txt");
    int N;
    cin >> N;
    vector<int> H(N);
    for (int i = 0; i < N; i++)
        cin >> H[i];
    vector<vector<int>> dp(N, vector<int>(2, INT_MAX));
    dp[0][0] = 0;
    dp[0][1] = 0;
    for (int i = 1; i < N; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            if (j % 2 == 0)
                dp[i][j] = min(dp[i - 1][0], dp[i - 1][1]) + abs(H[i - 1] - H[i]);
            else if (i - 1 >= 1)
                dp[i][j] = min(dp[i - 2][0], dp[i - 2][1]) + abs(H[i] - H[i - 2]);
        }
    }
    cout << min(dp[N - 1][0], dp[N - 1][1]) << endl;
}