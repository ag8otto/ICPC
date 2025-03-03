// NOTE: it is recommended to use this even if you don't understand the following code.

#include <fstream>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main()
{
    ifstream cin("input4.txt");
    //ofstream cout("output.txt");

    string A, B;
    cin >> A;
    cin >> B;
    string C;
    size_t diff = 0;
    while (diff < A.size() && A[diff] == B[diff])
    {
        diff++;
    }
    C = A.substr(0, diff);
    while (diff < A.length() && diff < B.length())
    {
        char candidate = (A[diff] + B[diff]) / 2;
        C.push_back(candidate);
        if (candidate != A[diff])
        {
            cout << C << endl;
            return 0;
        }
        diff++;
    }
    while (diff <= A.size())
    {
        if (diff == A.size())
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