#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;
#define MAXN 300000
int N;
vector<int> P;

int main()
{
    ifstream cin("input.txt");
    ofstream cout("output.txt");

    cin >> N;
    P.resize(N);
    for (int i = 0; i < N; i++)
        cin >> P[i];
    sort(P.begin(), P.end(), [](const int a, const int b)
         { return a > b; });
    int sum = 0;
    for (int i = 0; i < N; i++)
        if ((i + 1) % 3 != 0)
            sum += P[i];

    cout << sum << endl;
    return 0;
}