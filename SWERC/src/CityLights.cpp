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
    cin >> N;
    cin >> K;
    vector<bool> light(N + 1, true);
    int count = 0;
    int max_lights = 0;
    for (int i = 0; i < K; i++)
    {
        int m;
        cin >> m;
        for (int j = 1; j <= N / m && m * j <= N; j++)
        {
            (light[m * j]) ? count++ : count--;
            light[m * j] = !light[m * j];
        }
        max_lights = max(max_lights, count);
    }
    cout << max_lights << endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ifstream cin("input.txt");
    test_case(cin);
}