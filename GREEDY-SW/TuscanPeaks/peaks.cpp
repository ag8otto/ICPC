// NOTE: it is recommended to use this even if you don't understand the following code.

#include <fstream>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
    // uncomment the two following lines if you want to read/write from files
    // ifstream cin("input.txt");
    // ofstream cout("output.txt");

    int N, M;
    cin >> N >> M;
    
    vector<int> A(N);
    for (int i = 0; i < N; ++i)
        cin >> A[i];
    
    vector<int> B(M);
    for (int i = 0; i < M; ++i)
        cin >> B[i];
    
    long long P = 0;
    
    
    // INSERT YOUR CODE HERE
    
    
    cout << P << endl;

    return 0;
}
