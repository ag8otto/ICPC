#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    ifstream cin("input0.txt");
    //  ofstream cout("output.txt");

    int N;
    long long K;
    vector<int> V;
    cin >> N >> K;
    V.resize(N);
    for (int i = 0; i < N; i++)
    {
        cin >> V[i];
        cout << V[i] << ' ';
    }
    cout << endl;
    int i = 0, j = 0;
    long long sum = 0;
    vector<pair<pair<int, int>, long long>> archi(N * (N + 1) / 2);
    int cont = 0;
    while (j < N)
    {
        sum += V[j];
        archi[cont] = {{i, j}, sum};
        j++;
        cont++;
        if (j == N)
        {
            i++;
            j = i;
            sum = 0;
        }
    }
    stable_sort(archi.begin(), archi.end(), [](const pair<pair<int, int>, long long> &a, const pair<pair<int, int>, long long> &b)
         { return a.second < b.second; });
    for (auto i : archi)
        cout << i.first.first << ' ' << i.first.second << " : " << i.second << endl;
    cout << endl;
    cout << archi[K - 1].first.first << ' ' << archi[K - 1].first.second;
    return 0;
}
