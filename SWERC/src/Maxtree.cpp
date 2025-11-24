#include <bits/stdc++.h>
using namespace std;
#define debug(x) cout << #x << " = " << x << '\n';
#define vdebug(a)         \
    cout << #a << " = ";  \
    for (auto x : a)      \
        cout << x << " "; \
    cout << '\n';

void test_case()
{
    int n;
    cin >> n;
    unordered_map<int, vector<int>> adj_list;
    for (int i = 0; i < n - 1; i++)
    {
        int u, v, x, y;
        cin >> u >> v >> x >> y;
        (x > y) ? adj_list[v].push_back(u) : adj_list[u].push_back(v);
    }

    vector<int> ans, visited(n + 1, 0);
    function<void(int)> dfs = [&](int node)
    {
        visited[node] = 1;
        for (auto i : adj_list[node])
        {
            if (visited[i] == 0)
                dfs(i);
        }
        ans.push_back(node);
    };

    for (int i = 1; i <= n; i++)
        if (!visited[i])
            dfs(i);

    vector<int> perm(n);
    reverse(ans.begin(), ans.end());
    for (int i = 0; i < n; i++)
    {
        perm[ans[i] - 1] = i + 1;
    }
    for (auto i : perm)
        cout << i << ' ';
    cout << endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--)
    {
        test_case();
    }
}
