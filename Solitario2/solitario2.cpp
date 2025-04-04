#include <iostream>
#include <vector>
#include <fstream>
#include <cassert>
using namespace std;


int gioca(int N, int M, vector<vector<int>> G)
{
   
}

int main()
{
    ifstream cin("solitario2.input0.txt");
    // ofstream cout("output.txt");
    int N, M;
    cin >> N >> M;

    vector<vector<int>> G(N, vector<int>(M));
    for (auto &x : G)
        for (auto &y : x)
            cin >> y;

    cout << gioca(N, M, G) << endl;
}
