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
pair<int, int> S, D;
int B, Co, T, N;
vector<int> C;
vector<pair<int, int>> P;
unordered_map<int, vector<pair<int, int>>> adj;
struct Edge
{
    int to;
    int dist;
    int weight;
};
vector<vector<Edge>> graph;
void dijkstra()
{
    vector<vector<int>> dp(N + 2, vector<int>(B + 1, INT_MAX));
    dp[0][0] = 0;

    // Priority queue: (co2, nodo, lunghezza_usata)
    using State = tuple<int, int, int>;
    priority_queue<State, vector<State>, greater<State>> pq;
    pq.push({0, 0, 0});

    while (!pq.empty())
    {
        auto [curCo2, u, curLen] = pq.top();
        pq.pop();
        if (curCo2 > dp[u][curLen])
            continue; // stato obsoleto

        for (auto &e : graph[u])
        {
            int nextLen = curLen + e.dist;
            if (nextLen > B)
                continue; // supera il vincolo
            int nextCo2 = curCo2 + e.weight;
            if (nextCo2 < dp[e.to][nextLen])
            {
                dp[e.to][nextLen] = nextCo2;
                pq.push({nextCo2, e.to, nextLen});
            }
        }
    }
    // Trova il minimo tra tutti gli stati del nodo N+1
    int result = INT_MAX;
    for (long long l = 0; l <= B; ++l)
        result = min(result, dp[N + 1][l]);
    if (result == INT_MAX)
        cout << -1 << endl;
    else
        cout << result << endl;
}
int dist(pair<int, int> a, pair<int, int> b)
{
    int dx = (a.first - b.first);
    int dy = (a.second - b.second);
    return ceil(sqrt(dx * dx + dy * dy));
}
void take_input(ifstream &cin)
{
    cin >> S.first >> S.second;
    cin >> D.first >> D.second;
    cin >> B;
    cin >> Co;
    cin >> T;
    C.resize(T);
    for (int i = 0; i < T; i++)
        cin >> C[i];
    cin >> N;
    P.resize(N);
    graph.resize(N + 2);
    graph[0].push_back({N + 1, dist(S, D), dist(S, D) * Co});
    for (int i = 0; i < N; i++)
    {
        cin >> P[i].first >> P[i].second;
        int dSi = dist(S, P[i]);
        int dDi = dist(D, P[i]);
        graph[0].push_back({i + 1, dSi, dSi * Co});
        graph[i + 1].push_back({N + 1, dDi, dDi * Co});
        int num_Edges;
        cin >> num_Edges;
        for (int j = 0; j < num_Edges; j++)
        {
            int to, mode;
            cin >> to >> mode;
            adj[i].push_back({to, mode});
            adj[to].push_back({i, mode});
        }
    }
}

void test_case()
{
    for (int i = 0; i < N; i++)
        for (auto j : adj[i])
            graph[i + 1].push_back({j.first + 1, dist(P[i], P[j.first]), dist(P[i], P[j.first]) * C[j.second - 1]});
    dijkstra();
}

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ifstream cin("input.txt");
    take_input(cin);
    test_case();
}