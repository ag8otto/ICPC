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
    int X, Y, N;
    cin >> X >> Y;
    cin >> N;
    vector<int> countX(Y);
    vector<int> minY(X, INT_MAX);
    vector<int> maxY(X, -1);

    for (int i = 0; i < N; i++)
    {
        int x, y;
        cin >> x >> y;
        minY[x] = min(minY[x], y);
        maxY[x] = max(maxY[x], y);
    }
    vector<int> ordinates;
    for (int i = 0; i < minY.size(); i++)
    {

        if (minY[i] != INT_MAX)
            ordinates.push_back(minY[i]);
        if (maxY[i] != -1)
            ordinates.push_back(maxY[i]);
    }
    sort(ordinates.begin(), ordinates.end());
    int median = ordinates[ordinates.size() / 2];
    long long cost = X - 1;
    for (int i = 0; i < X; i++)
    {
        if (maxY[i] == -1 || maxY[i] == INT_MAX)
            continue;
        if (minY[i] < median && median < maxY[i])
            cost += 2 * abs(median - minY[i]) + 2 * abs(maxY[i] - median);
        else
            cost += 2 * (max(abs(maxY[i] - median), abs(median - minY[i])));
    }
    cout << cost << endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ifstream cin("/home/agostinodon/Scaricati/swerc_testcases/monumenttour/data/secret/test12.in");
    test_case(cin);
}