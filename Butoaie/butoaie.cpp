#include <iostream>
#include <fstream>
#include <vector>
#include <cassert>
#include <algorithm>
#include <cmath>
using namespace std;

bool isPossible(int X, vector<int> V, int best, int worst, int K)
{
    vector<int> D(V.size());
    long int sum = 0;
    for (size_t i = 0; i < V.size(); i++)
    {
        D[i] = static_cast<int>(ceil(static_cast<double>(V[i] - X * worst) / (best - worst)));
        if (D[i] > X)
            return false;
        sum += D[i];
    }
    if (sum > (long)(K * X))
        return false;
    else
        return true;
}
int main()
{
    ifstream cin("input0.txt");
    // ofstream cout("output.txt");
    int N, K, Q, P;
    cin >> N >> K;
    cin >> P >> Q;
    vector<int> V(N);
    for (int i = 0; i < N; i++)
        cin >> V[i];
    int best, worst;
    if (P > Q)
    {
        best = P;
        worst = Q;
    }
    else
    {
        best = Q;
        worst = P;
        K = N - K;
    }
    cout << best << ' ' << K << endl;
    cout << worst << ' ' << N - K << endl;
    int max = *max_element(V.begin(), V.end());
    int left = max / best, right = max / worst; // Definisci l'intervallo di ricerca
    int result = right;
    while (left <= right)
    {
        int mid = (right + left) / 2;
        if (isPossible(mid, V, best, worst, K))
        {
            result = mid;
            right = mid - 1; // Cerca nella metà sinistra
        }
        else
        {
            left = mid + 1; // Cerca nella metà destra
        }
    }
    cout << result << endl; // Stampa il risultato
    return 0;
}