#include <iostream>
#include <fstream>
#include <vector>
#include <set>
using namespace std;
int main()
{
    ifstream cin("input0.txt");
    //ofstream cout("output.txt");

    int N;
    long long M, L;
    vector<long long> D;
    cin >> N >> M >> L;
    D.resize(N);

    for (int i = 0; i < N; i++)
        cin >> D[i];

    int min = -1;
    if(M >= L) min = N;
    if (N == 1){
        (D[0] + M > L && D[0] - M < 0) ? min = 1 : min = 0;
    }else{
        if(D[0] > M || D[N-1] + M < L) min = 0;
        if(D[0] == M || D[N-1] + M == L) min = 1;
        else{
            set<int> Delta_Spot;
            for (int i = 0; i < N; i++){
              (D[i] - M < 0) ? Delta_Spot.insert(0) : Delta_Spot.insert(D[i] - M);
              (D[i] + M > L) ? Delta_Spot.insert(L) : Delta_Spot.insert(D[i] + M);  
            }
            
        }
    }   
    cout << min << endl;
    return 0;
}