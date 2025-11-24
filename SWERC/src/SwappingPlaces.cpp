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
unordered_map<string, set<string>> rules;
void test_case(ifstream &cin)
{
    int S, L, N;
    cin >> S >> L >> N;
    vector<string> species(S);
    for (int i = 0; i < S; i++)
        cin >> species[i];
    sort(species.begin(), species.end());
    for (int i = 0; i < L; i++)
    {
        string sp1, sp2;
        cin >> sp1 >> sp2;
        rules[sp1].insert(sp2);
        rules[sp2].insert(sp1);
    }
    vector<string> sequence(N);
    for (int i = 0; i < N; i++)
        cin >> sequence[i];

    vector<string> res;
    while (sequence.size() > 0)
    {
        for (int i = 0; i < S; i++)
        {
            for (int j = 0; j < sequence.size(); j++)
            {
                if (sequence[j] == species[i])
                {
                    res.push_back(species[i]);
                    auto it = find(sequence.begin(), sequence.end(), species[i]);
                    if (it != sequence.end())
                        sequence.erase(it);
                    break;
                }
                if (!rules[species[i]].count(sequence[j]))
                    break;
            }
        }
    }
    for (auto i : res)
        cout << i << ' ';
    cout << endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ifstream cin("input.txt");
    test_case(cin);
}