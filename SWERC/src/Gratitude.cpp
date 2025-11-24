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
    int N, K;
    cin >> N >> K;
    unordered_map<string, pair<int, int>> counter;
    for (int i = 0; i <= 3 * N; i++)
    {
        string line;
        getline(cin, line);
        counter[line].first++;
        counter[line].second = i;
    }

    vector<pair<string, pair<int, int>>> res;
    for (auto x : counter)
        res.push_back({x.first, {x.second.first, x.second.second}});
    sort(res.begin(), res.end(), [](const auto &a, const auto &b)
         {
        if (a.second.first != b.second.first)
            return a.second.first > b.second.first;
        return a.second.second > b.second.second; });

    for (int i = 0; i < K; i++)
        cout << res[i].first << endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ifstream cin("input.txt");
    test_case(cin);
}