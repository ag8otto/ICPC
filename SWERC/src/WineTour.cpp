#include <bits/stdc++.h>

using namespace std;

int main()
{
    ifstream cin("input.txt");

    int numT;
    cin >> numT;
    for (int i = 0; i < numT; i++)
    {
        int nBottles, nCrit;
        cin >> nBottles >> nCrit;
        vector<int> red(nCrit);
        vector<int> white(nCrit);
        int maxR = 0, maxW = 0;
        for (int i = 0; i < nCrit; i++)
        {
            cin >> red[i] >> white[i];
            maxR = max(maxR, red[i]);
            maxW = max(maxW, white[i]);
        }
        if (maxR + maxW > nBottles)
        {
            cout << "IMPOSSIBLE" << endl;
            continue;
        }
        string res;
        for (int i = 0; i < maxR; i++)
            res.append("R");
        for (int i = 0; i < maxW; i++)
            res.append("W");
        for (int i = 0; i < nBottles -(maxR + maxW); i++)
            res.append("W");
    
        cout << res << endl;
    }
}