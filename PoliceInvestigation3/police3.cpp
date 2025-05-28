#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>
#include <numeric>
#include <algorithm>
using namespace std;

int main()
{
    // ifstream cin("input0.txt");
    //  ofstream cout("output.txt");

    int N;
    cin >> N;

    vector<int> T(N);
    for (int i = 0; i < N; i++)
        cin >> T[i];

    vector<int> S(N, -1);
    int prev_stop = T[0];
    int prev_skip = 0;

    for (int i = 1; i < N; i++)
    {
        int curr_stop = min(prev_stop, prev_skip) + T[i];
        int curr_skip = prev_stop;

        prev_stop = curr_stop;
        prev_skip = curr_skip;
    }
    cout << min(prev_stop, prev_skip) << endl;
    return 0;
}
