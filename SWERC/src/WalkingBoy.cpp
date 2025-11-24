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

string test_case(ifstream &cin)
{
    int N;
    cin >> N;
    int prev = 0, count = 0;
    for (int i = 0; i < N; i++)
    {
        int time;
        cin >> time;
        count += floor((time - prev) / 120);
        prev = time;
    }
    count += floor((1440 - prev) / 120);
    return (count >= 2) ? "YES" : "NO";
}

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ifstream cin("input.txt");
    int t;
    cin >> t;
    for (int i = 0; i < t; i++)
        cout << test_case(cin) << endl;
}