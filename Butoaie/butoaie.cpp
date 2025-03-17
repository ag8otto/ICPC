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
        D[i] = ((V[i] - X * worst + best - worst - 1) / (best - worst));
        if (D[i] > X)
            return false;
        if (D[i] > 0)
            sum += D[i];
    }
    if (sum >= (K * X)){
        return false;
    }else
        return true;
}
int main()
{
    ifstream cin("input.txt");
    ofstream cout("output.txt");
    int N, K, Q, P;
    cin >> N >> K;
    cin >> P >> Q;
    vector<int> V(N);
    for (int i = 0; i < N; i++)
    {
        cin >> V[i];
    }
    int best, worst, disp = K;
    if (P > Q)
    {
        best = P;
        worst = Q;
    }
    else
    {
        best = Q;
        worst = P;
        disp = N - K;
    }

    int max = *max_element(V.begin(), V.end());
    int left = (max / best);
    int right = static_cast<int>(ceil(static_cast<double>(max) / worst)); 
    while (left <= right)
    {
        int mid = (right + left) / 2;
        int sum = 0;
        for (int i = 0; i < N; i++)
        {
            if(V[i] <= worst * mid) continue;

            int cell_need = (V[i] - worst*mid + best - worst - 1) / (best - worst);
            if(cell_need > mid){
                sum += disp * mid + 1;
                break;
            }
            sum += cell_need;
        }
        if(sum <= disp * mid)
            right = mid - 1;
        else
            left = mid + 1;
    }
    cout << right + 1 << endl; // Stampa il risultato
    return 0;
}