#include <iostream>
#include <fstream>
#include <set>
// constraints
using namespace std;
// input data
int N1, N2;

int main() {
    ifstream cin("input0.txt");
    ofstream cout("output.txt");

    cin >> N1 >> N2;
    set<int> S1;
    int count = 0;
    // insert your code here
    for (size_t i = 0; i < N1; i++){
        int val;
        cin >> val;
        S1.insert(val);
    }
    for (size_t i = 0; i < N2; i++)
    {
        int val;
        cin >> val;
        if(S1.find(val) != S1.end()) count++;
    }
    
    cout << count << endl;
    return 0;
}
