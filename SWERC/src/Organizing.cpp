#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>
using namespace std;

int main()
{
    ifstream cin("input.txt");
    int num_cases;
    cin >> num_cases;

    for (int i = 0; i < num_cases; i++)
    {
        int num_test;
        cin >> num_test;
        vector<int> difficulties(11, -10000);
        for (int j = 0; j < num_test; j++)
        {
            int b, d;
            cin >> b >> d;
            difficulties[d] = max(difficulties[d], b);
        }
        int sum = 0;
        for (int j = 1; j <= 10; j++)
            sum += difficulties[j];

        if (sum < 0)
            cout << "MOREPROBLEMS" << endl;
        else
            cout << sum << endl;
    }
}