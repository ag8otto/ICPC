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

vector<set<int>> adj;
set<int> S;
vector<set<int>> goal;

int t = 0;
int N, M, T;

void annotate(int n, int r)
{
    if (goal[n].count(r))
        return;
    if (goal[n].size() >= 2)
        return;
    goal[n].insert(r);
    for (auto u : adj[n])
        annotate(u, r);
}
void test_case(ifstream &cin)
{
    cin >> N >> M >> T;
    adj.resize(N);
    goal.resize(N);
    for (int i = 0; i < M; i++)
    {
        int from, to;
        cin >> from >> to;
        if (to == T)
            S.insert(from);
        else
            adj[to].insert(from);
    }
    for (auto c : S)
        annotate(c, c);
    set<int> res;
    for (auto i : S)
        if (goal[i].size() == 1)
            res.insert(i);
    cout << res.size() << endl;
    for (auto x : res)
        cout << x << endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ifstream cin("input.txt");
    test_case(cin);
}