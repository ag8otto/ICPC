#include <bits/stdc++.h>

using namespace std;

string clear(string ref, int *count)
{
    string temp;
    char curr, seen = 0;
    for (int i = 0; i < ref.length(); i++)
    {
        curr = ref[i];
        if (curr == 'B')
            (*count)++;
        else
        {
            (curr == seen) ? temp.pop_back() : temp.push_back(curr);
            (curr == seen) ? seen = temp.back() : seen = curr;
        }
    }
    return temp;
}
int main()
{
    ifstream cin("input.txt");
    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        string u, v;
        cin >> u >> v;
        int countuB = 0, countvB = 0;
        string clU = clear(u, &countuB);
        string clV = clear(v, &countvB);

        (clU == clV && (countuB % 2) == (countvB % 2)) ? cout << "YES" << endl : cout << "NO" << endl;
    }
}