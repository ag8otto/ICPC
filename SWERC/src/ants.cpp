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
    int N;
    cin >> N;
    vector<int> ants(N, INT_MAX);
    for (int i = 0; i < N; i++)
    {
        long long temp; // leggo prima in long long per controllare overflow
        if (!(cin >> temp))
        {
            cin.clear();                                         // resetta lo stato di errore
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // salta la linea
            continue;
        }
        if (temp < 0 || temp > N)
        {
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // salta la linea
            continue;
        }
        int num = static_cast<int>(temp);
        ants[i] = num;
    }
    sort(ants.begin(), ants.end());
    for (auto i : ants)
    {
        cout << i << ' ';
    }
    cout << endl;

    for (int i = 0; i < N; i++)
    {
        if (i != ants[i])
        {
            cout << i << endl;
            return;
        }
    }
    cout << N << endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ifstream cin("input.txt");
    test_case(cin);
}