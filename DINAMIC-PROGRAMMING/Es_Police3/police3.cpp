#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

int main()
{
    int N;
    cin >> N;

    vector<int> T(N);
    for (int i = 0; i < N; i++)
        cin >> T[i];

    int prev_skip = T[0];
    int prev_stop = 0;

    for (int i = 1; i < N; i++)
    {
        int curr_skip = min(prev_skip, prev_stop) + T[i];
        int curr_stop = prev_skip;

        prev_skip = curr_skip;
        prev_stop = curr_stop;
    }

    cout << min(prev_skip, prev_stop) << endl; // print the result
    return 0;
}
