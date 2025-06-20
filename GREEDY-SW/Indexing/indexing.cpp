#include <fstream>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main()
{
    ifstream cin("input.txt");
    ofstream cout("output.txt");

    string A, B;
    cin >> A;
    cin >> B;
    string C;
    size_t diff = 0;
    while (diff < A.size() && A[diff] == B[diff])
        diff++;
    C = A.substr(0, diff);

    while (diff < A.length() && diff < B.length())
    {
        for (char i = A[diff]; i <= B[diff]; i++)
        {
            C.push_back(i);
            if (A < C && C < B)
            {
                cout << C << endl;
                return 0;
            }
            C.pop_back();
        }
        C.push_back(A[diff]);
        diff++;
    }
    while (diff <= A.length())
    {
        if (diff == A.length())
        {
            C.push_back('a');
        }
        else
        {
            if (A[diff] == 'z')
            {
                C.push_back('z');
            }
            else
            {
                C.push_back(A[diff] + 1);
                cout << C << endl;
                return 0;
            }
        }
        diff++;
    }
    if (!(A < C && C < B))
        cout << -1 << endl;
    else
        cout << C << endl;
    return 0;
}

