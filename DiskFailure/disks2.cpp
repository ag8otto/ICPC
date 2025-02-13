// insert brief description of the solution here
// NOTE: it is recommended to use this even if you don't understand the following code.

#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

int main() {
ifstream cin("input0.txt");
ofstream cout("output.txt");

    int N, T;
    cin >> N >> T;

    vector<int> A(N), B(N);
    for (int i = 0; i < N; i++) {
        cin >> A[i] >> B[i];
    }
    int i;
    for (i = 0; i < N-1; i++)
    {
        if(A[i+1] + 24 - B[i] >= T) break;
    }
    if (i == N-1) i = -1;
    cout << i << endl; // print the result
    
    return 0;
}
