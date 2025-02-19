#include <fstream>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
    ifstream cin("input0.txt");
    ofstream cout("output.txt");

    int N, M, R, G, B;
    cin >> N >> M >> R >> G >> B;
    
    vector<string> grid(N, string(M, '_'));
    bool ans = true;
    
    
    
    
    if (ans) {
        cout << "YES" << endl;
        for (int i = 0; i < N; ++i)
            cout << grid[i] << endl;
    } else {
        cout << "NO" << endl;
    }

    return 0;
}
