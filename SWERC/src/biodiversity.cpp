#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define debug(x) cout << #x << " = " << x << '\n';
#define vdebug(a)         \
    cout << #a << " = ";  \
    for (auto x : a)      \
        cout << x << " "; \
    cout << '\n';
typedef vector<ll> vi;
typedef pair<ll, ll> pi;

void test_case(ifstream &cin)
{
    int N;
    cin >> N;
    unordered_map<string, int> animals;
    for (int i = 0; i < N; i++)
    {
        string line;
        cin >> line;
        animals[line]++;
    }
    for (auto i : animals)
    {
        if (i.second > N / 2)
        {
            cout << i.first << endl;
            return;
        }
    }
    cout << "NONE" << endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ifstream cin("input.txt");
    test_case(cin);
}