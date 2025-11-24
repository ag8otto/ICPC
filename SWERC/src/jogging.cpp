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
struct Edge
{
    int to;
    int label;
};
typedef struct Edge Edge;
unordered_map<int, vector<Edge>> graph;
ll I, S, L, U;

vector<ll> djkistra(int origin)
{
    vector<ll> dist(I, INT_MAX);
    dist[origin] = 0;
    priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>> pq;
    pq.push({origin, 0});
    while (!pq.empty())
    {
        auto [d, u] = pq.top();
        pq.pop();
        if (d > U)
            continue;
        for (auto edge : graph[u])
        {
            int dest = edge.to;
            int weight = edge.label;
            if (dist[dest] > d + weight)
            {
                dist[dest] = d + weight;
                pq.push({dist[dest], dest});
            }
        }
    }
    return dist;
}
void test_case(ifstream &cin)
{
    cin >> I >> S >> L >> U;
    for (int i = 0; i < S; i++)
    {
        int from, to, label;
        cin >> from >> to >> label;
        graph[from].push_back({to, label});
        graph[to].push_back({from, label});
    }
    vector<ll> dist = djkistra(0);

    set<pair<int, int>> seen;
    for (int i = 0; i < dist.size(); i++)
        if (dist[i] <= (U - 1) / 2)
            for (auto x : graph[i])
                seen.insert({min(i, x.to), max(i, x.to)});
    cout << seen.size() << endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ifstream cin("input.txt");
    test_case(cin);
}