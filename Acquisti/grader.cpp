#include <cassert>
#include <iostream>
#include <fstream>
#include <utility>
#include <vector>
#include <numeric>
using namespace std;
typedef long long ll;

bool isPossible(long long cap, long long Nitems, vector<long long> S)
{
    long long weight = 0;
    long long items = 0;
    for (long long i = 0; items <= Nitems && i < (ll)S.size(); i++)
    {
        long long curr_items = min(S[i], Nitems - items);
        long long curr_weight = curr_items * i;

        weight += curr_weight;
        items += curr_items;
    }
    return weight <= cap;
}

vector<long long> calcola(int T, int M, vector<long long> S, vector<long long> P)
{
    vector<long long> R(P.size(), 0);
    long long max_items = accumulate(S.begin(), S.end(), 0);
    for (long long i = 0; i < (ll)P.size(); i++)
    {
        long long min = 0, max = max_items;
        while (min <= max)
        {
            long long mid = (min + max) / 2;
            if (isPossible(P[i], mid, S))
                min = mid + 1;
            else
                max = mid - 1;
        }
        R[i] = max;
    }
    return R;
}

int main()
{
    ifstream cin("acquisti.input2.txt");
    int T, M;
    cin >> T >> M;

    vector<long long> S(T), P(M);

    for (long long &x : S)
        cin >> x;
    for (long long &x : P)
        cin >> x;

    auto R = calcola(T, M, S, P);

    for (long long x : R)
        cout << x << ' ';
    cout << endl;

    return 0;
}