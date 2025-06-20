#include <fstream>
#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;

int main()
{
    ifstream cin("input.txt");
    ofstream cout("output.txt");

    int N, K;
    cin >> N >> K;
    long long int mana = 0;
    if (N == 1)
    {
        long long int val;
        cin >> val;
        mana = val * K;
    }
    else if (K < N)
    {
        pair<long long int, long long int> mano;
        cin >> mano.first;
        for (int i = 0; i < K; i++)
        {
            cin >> mano.second;
            long long int minC = min(mano.first, mano.second);
            mana += minC;
            if (minC == mano.first)
                mano.first = mano.second;
        }
    }
    else
    {
        pair<long long int, long long int> mano;
        vector<long long int> cards(N);
        for (int i = 0; i < N; i++)
            cin >> cards[i];
        mano.first = cards[0];
        long long int cycle_mana = 0;
        long long int rest_mana = 0;
        for (int i = 1; i < N; i++)
        {
            mano.second = cards[i];
            int minC = min(mano.first, mano.second);
            cycle_mana += minC;
            if (i <= (K % (N - 1)))
                rest_mana = cycle_mana;
            if (minC == mano.first)
                mano.first = mano.second;
        }
        mana = cycle_mana * (K / (N - 1)) + rest_mana;
    }
    cout << mana << endl;
    return 0;
}
