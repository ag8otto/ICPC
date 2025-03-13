#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

// input data

int main()
{
    ifstream cin("input1.txt");
    //  ofstream cout("output.txt");
    int N;
    long long M, L;
    vector<long long> D;
    cin >> N >> M >> L;
    D.resize(N);
    for (int i = 0; i < N; i++)
        cin >> D[i];

    if (N == 1)
    {
        (D[0] + M > L && D[0] - M < 0) ? cout << 1 << endl : cout << 0 << endl;
        return 0;
    }
    int min = N;
    
    
    cout << min << endl;
    return 0;
}
