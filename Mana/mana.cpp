#include <fstream>
#include <iostream>
#include <string>
#include <queue>
using namespace std;

int main() {
    ifstream cin("input2.txt");
    ofstream cout("output.txt");

    int N, K;
    cin >> N >> K;

    queue<int> C;
    int min;
    cin >> min;
    for (int i = 1; i < K ++; i){
        int val;
        cin >> val;

        C.push(val);
    }
    cout << 0 << endl;

    return 0;
}
