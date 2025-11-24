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
double X, Y;
int n;
vector<pair<double, double>> coord;
vector<double> min_x, min_y, max_x, max_y;

void MAKE_SET(vector<int> &P, vector<int> &H, int x)
{
    P[x] = x;
    H[x] = 0;
}
int FIND(vector<int> &P, int x)
{
    if (P[x] == x)
        return x;
    else
        return P[x] = FIND(P, P[x]);
}
void UNION(vector<int> &P, vector<int> &H, int x, int y)
{
    int a = FIND(P, x);
    int b = FIND(P, y);
    if (a != b)
    {
        int from = a, to = b;
        if (H[a] > H[b])
        {
            int temp = from;
            from = to;
            to = temp;
        }

        P[from] = to;
        if (H[from] == H[to])
            H[to]++;
        min_x[to] = min(min_x[to], min_x[from]);
        min_y[to] = min(min_y[to], min_y[from]);
        max_x[to] = max(max_x[to], max_x[from]);
        max_y[to] = max(max_y[to], max_y[from]);
    }
}
double dist(double Xi, double Yi, double Xf, double Yf)
{
    return sqrt((Xf - Xi) * (Xf - Xi) + (Yf - Yi) * (Yf - Yi));
}

bool split_graph()
{
    for (int i = 0; i < n; i++)
    {
        if (min_x[i] < 0 && max_x[i] > X)
        {
            return true; // BARRIERA ORIZZONTALE
        }
        else if (min_y[i] < 0 && max_y[i] > Y)
        {
            return true; // BARRIERA VERTICALE
        }
        else if (min_x[i] < 0 && min_y[i] < 0)
        {
            return true; // BARRIERA SULLA DIAGONALE (0,0)(X,Y)
        }
        else if (max_x[i] > X && max_y[i] > Y)
        {
            return true; // BARRIERA SULLA DIAGONALE (Y,0)(X,0)
        }
    }
    return false;
}
bool isSafe(double d)
{
    vector<int> P(n), H(n);
    min_x.clear();
    min_y.clear();
    max_x.clear();
    max_y.clear();
    for (int i = 0; i < n; ++i)
    {
        MAKE_SET(P, H, i);
        min_x[i] = coord[i].first - d;
        min_y[i] = coord[i].second - d;
        max_x[i] = coord[i].first + d;
        max_y[i] = coord[i].second + d;
    }
    for (int i = 0; i < n; i++)
        for (int j = i + 1; j < n; j++)
            if (dist(coord[i].first, coord[i].second, coord[j].first, coord[j].second) < 2 * d)
                UNION(P, H, i, j);

    return !split_graph();
}
void test_case()
{
    cin >> X >> Y;
    cin >> n;
    coord.resize(n);
    min_x.resize(n);
    min_y.resize(n);
    max_x.resize(n);
    max_y.resize(n);

    for (int i = 0; i < n; i++)
    {
        cin >> coord[i].first >> coord[i].second;
    }

    double left = 0, right = min(X, Y);
    const double EPS = 1e-8;
    double d;
    while (right - left > EPS)
    {
        d = (left + right) / 2;
        if (isSafe(d))
            left += (d - left) / 2;
        else
            right -= (d - left) / 2;
    }
    cout << fixed << setprecision(6) << d << '\n';
}

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    test_case();
}