#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
// input data
using namespace std;
struct Edge
{
    int point1;
    int point2;
    int cost;
};

int FIND(vector<int> &P, int x);
void UNION(vector<int> &P, vector<int> &R, int x, int y);

int main()
{
    int N, M, i;
    cin >> N >> M;
    vector<struct Edge> A(M);
    for (i = 0; i < M; i++)
        cin >> A[i].point1 >> A[i].point2 >> A[i].cost;

    sort(A.begin(), A.end(), [](const Edge &a, const Edge &b)
         { return a.cost > b.cost; });

    vector<int> P(N, -1), R(N, 0);
    int solution = A[0].cost;
    for (int i = 0; i < N; i++)
        P[i] = i;
    for (int i = 0; i < M; i++)
    {
        if (FIND(P, A[i].point1) != FIND(P, A[i].point2))
        {
            UNION(P, R, A[i].point1, A[i].point2);
            solution = min(solution, A[i].cost);
        }
    }
    cout << solution << endl;
    return 0;
}

int FIND(vector<int> &P, int x)
{
    if (P[x] == x)
        return x;
    else
        return P[x] = FIND(P, P[x]);
}
void UNION(vector<int> &P, vector<int> &R, int x, int y)
{
    int a = FIND(P, x);
    int b = FIND(P, y);
    if (a != b)
    {
        if (R[a] < R[b])
        {
            P[a] = b;
        }
        else
        {
            P[b] = a;
            if (R[a] == R[b])
                R[a]++;
        }
    }
}