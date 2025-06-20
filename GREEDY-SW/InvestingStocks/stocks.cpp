// NOTE: it is recommended to use this even if you don't understand the following code.

#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

// input data
int N;
vector<int> V, S;

int main() {
//  uncomment the following lines if you want to read/write from files
    ifstream cin("input.txt");
    ofstream cout("output.txt");

    cin >> N;
    V.resize(N);
    S.resize(N);
    for (int i=0; i<N; i++)
        cin >> V[i];
    for (int i=0; i<N; i++)
        cin >> S[i];

    int max = 0;
    int sum = 0;
    for (int i = 0; i < N; i++)
    {
        if(S[i] == 1){
            if(sum == 0) sum = V[i];
            else if(V[i] >= V[i-1]){
                sum += V[i];
            }else{
                if(sum > max){
                    max = sum;
                }
                sum = V[i];
            }
        }else{
            if(sum > max) 
                max = sum;
            sum = 0;
        }
    }
    if(sum > max) max = sum;
    cout << max << endl; // print the result
    return 0;
}
