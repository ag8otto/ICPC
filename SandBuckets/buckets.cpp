// NOTE: it is recommended to use this even if you don't understand the following code.

#include <iostream>
#include <fstream>
#include <set>

using namespace std;

// input data
int N, i;
set<int> D;

int main() {
    ifstream cin("input1.txt");
    ofstream cout("output.txt");

    cin >> N;
    for (int i=0; i<N; i++){
        int value;
        cin >> value;
        if(D.insert(value).second == false){
            cout << "Impossible" << endl;
            return 0;
        }
    }

    cout << "Ok"; // print the result
    return 0;
}
