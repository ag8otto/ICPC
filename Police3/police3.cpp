// NOTE: it is recommended to use this even if you don't understand the following code.

#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>
#include <numeric>
using namespace std;

int main()
{
    ifstream cin("input0.txt");
    //  ofstream cout("output.txt");

    int N;
    cin >> N;

    vector<int> T(N);
    for (int i = 0; i < N; i++)
        cin >> T[i];

    vector<int> S(N, -1);
    for (size_t i = 0; i < N; i++)
    {
        /* code */
    }
    
    cout << 42 << endl; // print the result
    return 0;
}
