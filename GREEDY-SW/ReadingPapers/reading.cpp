#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;

int N, L;
vector<int> P, D;

int main() {
    ifstream cin("input.txt");
    ofstream cout("output.txt");

    cin >> N >> L;
    P.resize(N);
    D.resize(N);
    for (int i=0; i<N; i++)
        cin >> P[i] >> D[i];
    int max = 0;
    if(D[0] == 0){
        max += *max_element(P.begin(), P.end());
    }else{
        for (int i = 0; i < L && P.size() > 0; i++)
        {
            auto it = max_element(P.begin(), P.end());
            max += *it;
            P.erase(it);
        }
        
    }
    cout << max << endl; // print the result
    return 0;
}
