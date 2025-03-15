#include <iostream>
#include <fstream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;
int main()
{
    ifstream cin("input0.txt");
    // ofstream cout("output.txt");

    int N;
    long long M, L;
    vector<long long> D;
    cin >> N >> M >> L;
    D.resize(N);

    for (int i = 0; i < N; i++)
        cin >> D[i];

    int checkspot = -1;
    if (M >= L)
        checkspot = N;
    else if (N == 1)
        (D[0] + M > L && D[0] - M < 0) ? checkspot = 1 : checkspot = 0;
    else
    {
        if (D[0] > M || D[N - 1] + M < L)
            checkspot = 0;
        else if (D[0] == M || D[N - 1] + M == L)
            checkspot = 1;
        else
        {
            map<long long, int> spot;
            for (int i = 0; i < N; i++)
            {
                long long start = max(0LL, D[i] - M);
                long long end = D[i] + M;
                spot[start]++;
                if (end + 1 < L)
                    spot[end + 1]--;
            }
            for (const auto &p : spot)
            {
                cout << "(" << p.first << ", " << p.second << ")" << endl;
            }
            checkspot = N;
            int currcheck = 0;
            for (auto &event : spot)
            {
                currcheck += event.second;
                checkspot = min(checkspot, currcheck);
            }
        }
    }
    cout << checkspot << endl;
    return 0;
}
