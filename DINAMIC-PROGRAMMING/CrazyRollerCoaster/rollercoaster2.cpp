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
    ifstream cin("input2.txt");
    int N;
    cin >> N;
    vector<int> H(N);

    for (int i = 0; i < N; i++)
        cin >> H[i];
    int Hmax = *max_element(H.begin(), H.end());
    int sol = INT_MAX;
    for (int k = 0; k < 2; k++)
    {
        vector<vector<int>> dp(N, vector<int>(Hmax + 1, INT_MAX));
        for (int j = 0; j <= Hmax; j++)
            dp[0][j] = pow(H[0] - j, 2);
        bool startUp = k % 2 == 0;
        for (int i = 1; i < N; i++)
        {
            bool currUp = i % 2 == startUp;
            if (currUp)
            {
                int min_prev = INT_MAX;
                for (int h = 0; h <= Hmax; h++)
                {
                    if (h > 0)
                        min_prev = min(min_prev, dp[i - 1][h - 1]);
                    if (min_prev != INT_MAX)
                        dp[i][h] = min(dp[i][h], min_prev + (H[i] - h) * (H[i] - h));
                }
            }
            else
            {
                int min_prev = INT_MAX;
                for (int h = Hmax; h >= 0; h--)
                {
                    if (h < Hmax)
                        min_prev = min(min_prev, dp[i - 1][h + 1]);
                    if (min_prev != INT_MAX)
                        dp[i][h] = min(dp[i][h], min_prev + (H[i] - h) * (H[i] - h));
                }
            }
        }
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j <= Hmax; j++)
            {
                cout << dp[i][j] << ' ';
            }
            cout << endl;
        }
        
        sol = min(sol, *min_element(dp[N-1].begin(), dp[N-1].end()));
    }
    cout << sol << endl;
    return 0;
}