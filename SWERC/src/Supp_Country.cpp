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
int N, M;
unordered_map<int, vector<int>> adj;
void test_case(ifstream &cin)
{
    cin >> N >> M;
    for (int i = N; i < 2 * N; i++)
    {
        int num;
        cin >> num;
        adj[i].resize(num);
        for (int j = 0; j < num; j++)
        {
            int col;
            cin >> col;
            adj[i].push_back(col);
            adj[col].push_back(i);
        }
    }
    
}

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ifstream cin("input.txt");
    test_case(cin);
}