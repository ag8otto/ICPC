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

void fraction(double num)
{
    const int precision = 1000000;
    long long numeratore = std::round(num * precision);
    long long denominatore = precision;
    long long mcd = gcd(numeratore, denominatore);
    numeratore /= mcd;
    denominatore /= mcd;
    cout << numeratore << "/" << denominatore << endl;
}
void test_case(ifstream &cin)
{
    int n;
    cin >> n;
    vector<double> num(n);
    for (int i = 0; i < n; i++)
    {
        cin >> num[i];
    }
    vector<tuple<double, double, double>> res;
    double maxd = 0;
    for (double i = 0; i < n; i++)
    {
        while (res.size() != 0 && num[i] > get<1>(res.back()))
        {
            double x1 = get<0>(res.back());
            double x2 = i;
            if (x2 - x1 != 1)
            {
                double y1 = get<1>(res.back());
                double y2 = num[i];
                double ny2 = num[i - 1];
                double beauty = (x2 - x1) - (y2 - y1) / (y2 - ny2);
                maxd = max(maxd, beauty);
            }
            res.pop_back();
        }
        (i + 1 < n) ? res.emplace_back(i, num[i], num[i + 1]) : res.emplace_back(i, num[i], 0);
        if (res.size() >= 2)
        {
            tuple<double, double, double> p1 = res.back();
            tuple<double, double, double> p2 = res[res.size() - 2];
            double x1 = get<0>(p1);
            double y1 = get<1>(p1);
            double x2 = get<0>(p2);
            double y2 = get<1>(p2);
            double ny2 = get<2>(p2);
            if (x1 == x2 + 1)
                continue;
            double dist = double(x1 - x2) - ((double)(y2 - y1) / (double)(y2 - ny2));
            maxd = max(maxd, dist);
        }
    }
    if (maxd == 0)
        cout << maxd << endl;
    else
        fraction(maxd);
}

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ifstream cin("input.txt");
    test_case(cin);
}