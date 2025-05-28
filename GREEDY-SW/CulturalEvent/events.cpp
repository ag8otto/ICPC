#include <iostream>
#include <fstream>
#include <set>
#include <vector>
using namespace std;

int N, V;

int main()
{
    ifstream cin("input.txt");
    ofstream cout("output.txt");

    cin >> N >> V;
    multiset<int> Events;
    int count = 0;
    for (size_t i = 0; i < N; i++)
    {
        int val;
        cin >> val;
        Events.insert(val);
    }
    for (size_t i = 0; i < V; i++)
    {
        int val;
        cin >> val;
        auto it = Events.lower_bound(val);
        if (it != Events.end() && *it == val)
        {
            count++;
            Events.erase(it);
        }
        else if (it != Events.begin())
        {
            --it;
            count++;
            Events.erase(it);
        }
    }
    cout << count;
    return 0;
}
