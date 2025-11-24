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

vector<pair<int, int>> lines;
int N;

bool isFoundSquare(int len)
{
    if (len == 0)
        return true;
    multiset<int> S1, S2;
    for (int i = 0; i < len; i++)
    {
        S1.insert(lines[i].first);
        S2.insert(lines[i].second);
    }
    for (int i = len; i < N; i++)
    {
        if (*S2.begin() - *S1.rbegin() >= len - 1)
            return true;
        S1.erase(S1.find(lines[i - len].first));
        S2.erase(S2.find(lines[i - len].second));
        S1.insert(lines[i].first);
        S2.insert(lines[i].second);
    }

    return *S2.begin() - *S1.rbegin() >= len - 1;
};

void test_case(ifstream &cin)
{
    cin >> N;
    lines.resize(N);
    for (int i = 0; i < N; i++)
        cin >> lines[i].first >> lines[i].second;

    int min = 0, max = N;
    int mid;
    while (min < max)
    {
        mid = (min + max + 1) / 2;
        bool res = isFoundSquare(mid);
        cout << mid << " : " << res << endl
             << endl;
        if (res)
            min = mid;
        else
            max = mid - 1;
    }
    cout << min << endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ifstream cin("input.txt");
    test_case(cin);
}