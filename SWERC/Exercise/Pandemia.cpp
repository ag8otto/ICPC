#include <iostream>
#include <vector>
#include <fstream>
#include <climits>
#include <cmath>
#include <bits/stdc++.h>
using namespace std;
vector<pair<double, double>> coord(3);
double minY = DBL_MAX, minX = DBL_MAX;
double maxY = DBL_MIN, maxX = DBL_MIN;

double dist(double Xi, double Yi, double Xf, double Yf)
{
    return sqrt((Xf - Xi) * (Xf - Xi) + (Yf - Yi) * (Yf - Yi));
}
double findR(double X, double Y)
{
    double R = 0;
    for (int i = 0; i < 3; i++)
    {
        R = max(R, dist(coord[i].first, coord[i].second, X, Y) +
                       dist(coord[(i + 1) % 3].first, coord[(i + 1) % 3].second, X, Y));
    }
    return R;
}

double bestX(double Y)
{
    double xu = minX + (maxX - minX) / 3;
    double xd = minX + 2 * (maxX - minX) / 3;
    double ru = findR(xu, Y);
    double rd = findR(xd, Y);
    // cout << minX << ' ' << maxX << "  ru = " << ru << "|  rd = " << rd << endl;
    if (ru < rd)
    {
        maxX = xd;
        return xu;
    }
    else
    {
        minX = xu;
        return xd;
    }
}
double bestY(double X)
{
    double yu = minY + (maxY - minY) / 3;
    double yd = minY + 2 * (maxY - minY) / 3;
    double ru = findR(X, yu);
    double rd = findR(X, yd);
    // cout << minY << ' ' << minY << "  ru = " << ru << "|  rd = " << rd << endl
    if (ru < rd)
    {
        maxY = yd;
        return yu;
    }
    else
    {
        minY = yu;
        return yd;
    }
}

int main()
{
    ifstream cin("input.txt");

    for (int i = 0; i < 3; i++)
    {
        cin >> coord[i].first >> coord[i].second;
        minX = min(minX, coord[i].first);
        minY = min(minY, coord[i].second);

        maxX = max(maxX, coord[i].first);
        maxY = max(maxY, coord[i].second);
    }
    double eps = 1e-9;
    double prev;
    double curr = DBL_MAX;
    double Y = (maxY + minY) / 2;
    double X = (maxX + minX) / 2;
    do
    {
        double mx = bestX(Y);
        double my = bestY(X);
        prev = curr;
        curr = findR(mx, my);
        Y = my;
        X = mx;
    } while (abs(prev - curr) > eps);

    cout << curr << " (" << X << ',' << Y << ')' << endl;
    cout << endl
         << dist(2.5, 2.5, 0, 0) << endl;
    cout << findR(3, 1) << " (" << 3 << ',' << 1 << ')' << endl;
}