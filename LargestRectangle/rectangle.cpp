#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

int main()
{
    ifstream cin("input2.txt");
    ofstream cout("output.txt");

    int N;
    cin >> N;

    vector<long long> S(N);
    set<int> C;
    int size = 0;
    for (int i = 0; i < N; ++i)
    {
        long long val;
        cin >> val;
        if (C.insert(val).second == false)
        {
            S[size] = val;
            size++;
            C.erase(val);
        }
    }
    S.resize(size);
    sort(S.begin(), S.end());
    long long A = 0;
    if (size >= 2)
        A = S[size - 1] * S[size - 2];
    cout << A << endl;

    return 0;
}
