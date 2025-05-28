#include <fstream>
#include <iostream>
#include <string>
#include <vector>

using namespace std;
int main()
{
    ifstream cin("input.txt");
    ofstream cout("output.txt");

    int N;
    cin >> N;
    string S;
    cin >> S;

    int R = 0;

    int count = 0;
    vector<int> A, B, openings;
    for (size_t i = 0; i < S.length(); i++)
        if (S[i] == '(')
            openings.push_back(i);

    for (size_t i = 0; i < S.length(); i++)
    {
        if (S[i] == '(')
            count++;
        else
            count--;
        if (count < 0)
        {
            size_t index = openings.back();
            if (index > i)
            {
                char temp = S[index];
                S[index] = S[i];
                S[i] = temp;
                R++;
                A.push_back(i);
                B.push_back(index);
                count = 1;
                openings.pop_back();
            }
        }
    }
    cout << R << '\n';
    for (size_t i = 0; i < A.size(); i++)
        cout << A[i] << " " << B[i] << '\n';

    return 0;
}