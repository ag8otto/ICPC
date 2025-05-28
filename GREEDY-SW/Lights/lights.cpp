#include <fstream>
#include <iostream>
#include <vector>
#include <set>
using namespace std;

int main()
{
    ifstream cin("input.txt");
    ofstream cout("output.txt");

    int N, C;
    cin >> N >> C;
    vector<int> L(N);
    for (int i = 0; i < N; i++)
    {
        cin >> L[i];
    }

    int i = 0, j = 0;
    multiset<int> bin;
    set<int> unique;
    int min = N;
    while (j < N)
    {
        if ((int)unique.size() < C)
        {
            unique.insert(L[j]);
            bin.insert(L[j]);
            j++;
        }
        else
        {
            if ((j - i) < min)
                min = j - i;
            if (min == C)
                break;

            bin.erase(bin.find(L[i]));
            if (bin.count(L[i]) == 0)
                unique.erase(L[i]);
            i++;
        }
    }
    cout << min << endl; // print the result
    return 0;
}
