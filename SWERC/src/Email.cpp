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
unordered_map<int, vector<int>> adj_list;

int dist(int from, int *to)
{

    queue<int> q;
    q.push(from);
    vector<int> distanza(N + 1, -1);

    while (!q.empty())
    {
        int temp = q.front();
        q.pop();
        for (auto x : adj_list[temp])
        {
            if (distanza[x] == -1)
            {
                distanza[x] = distanza[temp] + 1;
                q.push(x);
            }
        }
    }
    int furth = 0;
    for (int i = 1; i <= N; i++)
    {
        if (distanza[i] > furth)
        {
            furth = distanza[i];
            *to = i;
        }
        if (distanza[i] == -1)
            return -1;
    }
    return furth;
}
void test_case()
{
    cin >> N >> M;
    for (int i = 0; i < M; i++)
    {
        int j, k;
        cin >> j >> k;
        adj_list[j].push_back(k);
        adj_list[k].push_back(j);
    }
    int curr = 0, next, len;
    for (int i = 0; i < 2; i++)
    {
        len = dist(curr, &next);
        curr = next;
    }
    (len == -1) ? cout << -1 << endl : cout << ceil(log(len) / log(2)) + 1 << endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    test_case();
}