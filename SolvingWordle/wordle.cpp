// NOTE: it is recommended to use this even if you don't understand the following code.

#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

// input data
int N;
vector<char> L;

int main() {
    ifstream cin("input1.txt");
    ofstream cout("output.txt");

    cin >> N;
    L.resize(N);
    int numUS = 0;
    for (int i=0; i<N; i++){
        cin >> L[i];
        if(L[i] == '_')numUS++;
    }
    int st = 26 - (L.size() - numUS);
    int res = 1;
    for (size_t i = 0; i < numUS; i++)
    {
        res *= st;
        st--;
    }
    

    cout << res << endl; // print the result
    return 0;
}
