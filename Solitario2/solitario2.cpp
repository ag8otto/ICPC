#include <iostream>
#include <vector>
#include <fstream>
#include <cassert>
using namespace std;

void print(vector<vector<int>> G)
{
    for (auto x : G)
    {
        for (auto y : x)
            cout << y << ' ';
        cout << endl;
    }
    cout << endl
         << endl;
}
// Funzione per verificare se aggiungere una X in una cella crea un tris
bool creaTris(const vector<vector<int>> &G, int N, int M, int r, int c)
{
    // Verifica riga
    for (int i = max(0, c - 2); i <= min(M - 3, c); ++i)
    {
        if (G[r][i] > 0 && G[r][i + 1] > 0 && G[r][i + 2] > 0)
            return true;
    }
    // Verifica colonna
    for (int i = max(0, r - 2); i <= min(N - 3, r); ++i)
    {
        if (G[i][c] > 0 && G[i + 1][c] > 0 && G[i + 2][c] > 0)
            return true;
    }
    // Verifica diagonale principale
    for (int i = -2; i <= 0; ++i)
    {
        if (r + i >= 0 && c + i >= 0 && r + i + 2 < N && c + i + 2 < M &&
            G[r + i][c + i] > 0 && G[r + i + 1][c + i + 1] > 0 && G[r + i + 2][c + i + 2] > 0)
            return true;
    }
    // Verifica diagonale secondaria
    for (int i = -2; i <= 0; ++i)
    {
        if (r + i >= 0 && c - i < M && r + i + 2 < N && c - i - 2 >= 0 &&
            G[r + i][c - i] > 0 && G[r + i + 1][c - i - 1] > 0 && G[r + i + 2][c - i - 2] > 0)
            return true;
    }
    return false;
}

// Funzione ricorsiva per il backtracking
int backtrack(vector<vector<int>> &G, int N, int M, int r, int c)
{
    if (r == N)
        return 0; // Fine della griglia
    print(G);
    int nextR = (c == M - 1) ? r + 1 : r;
    int nextC = (c == M - 1) ? 0 : c + 1;
    int maxX = 0;
    if (G[r][c] == 1)
    {
        if (creaTris(G, N, M, r, c))
            return 0;
        else
            return backtrack(G, N, M, nextR, nextC);
    }
    G[r][c] = 2;
    if (!creaTris(G, N, M, r, c))
        maxX = max(maxX, 1 + backtrack(G, N, M, nextR, nextC));
    G[r][c] = 0;
    maxX = max(maxX, backtrack(G, N, M, nextR, nextC));
    return maxX;
}
// Funzione principale da implementare
int gioca(int N, int M, vector<vector<int>> G)
{
    return backtrack(G, N, M, 0, 0);
}

int main()
{
    ifstream cin("solitario2.input0.txt");
    int N, M;
    cin >> N >> M;

    vector<vector<int>> G(N, vector<int>(M));
    for (auto &x : G)
        for (auto &y : x)
            cin >> y;

    cout << gioca(N, M, G) << endl;
}