#include <vector>
#include <numeric>
using namespace std;

bool isPossible(long long cap, long long Nitems, vector<long long> S)
{
    long long weight = 0;
    long long items = 0;
    for (long long i = 0; i < (long long)S.size() && items <= Nitems; i++)
    {
        long long curr_items = min(S[i], Nitems - items);
        long long curr_weight = curr_items * i;

        weight += curr_weight;
        items += curr_items;
    }
    if (weight <= cap)
        return true;
    else
        return false;
}

vector<long long> calcola(int T, int M, vector<long long> S, vector<long long> P)
{
    vector<long long> R(P.size(), 0);
    long long max_cap = accumulate(S.begin(), S.end(), 0);

    for (long long i = 0; i < (long long)P.size(); i++)
    {
        long long min = 0, max = max_cap;
        long long mid;
        while (min <= max)
        {
            mid = (min + max) / 2;
            if (isPossible(P[i], mid, S))
                min = mid + 1;
            else
                max = mid - 1;
        }
        R[i] = max;
    }
    return R;
}
