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
typedef pair<int, int> pii;

void test_case(ifstream &cin)
{
    int N;
    cin >> N;
    ll Area = 0;
    for (int i = 0; i < N; i++)
    {
        int P;
        cin >> P;
        vector<pii> Poly(P);
        for (int i = 0; i < P; i++)
            cin >> Poly[i].first >> Poly[i].second;
        ll sum = 0;
        for (int i = 0; i < P; ++i)
        {
            pii p1 = Poly[i];
            pii p2 = Poly[(i + 1) % P];
            sum += (ll)p1.first * p2.second - (ll)p2.first * p1.second;
        }
        Area += abs(sum) / 2;
    }
    cout << Area << "\n";
}
int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ifstream cin("input.txt");
    test_case(cin);
}