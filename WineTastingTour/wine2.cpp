#include <iostream>
#include <fstream>
#include <vector>
#include <numeric>
#include <algorithm>
#include <cmath>
using namespace std;

// input data

int main()
{
    ifstream cin("input1.txt");
    //ofstream cout("output.txt");
    int N;
    long long K;
    vector<int> V;
    cin >> N >> K;
    V.resize(N);
    for (int i = 0; i < N; i++)
        cin >> V[i];
    int max = 0;
    vector<int> acc(N);
    for (int i = 0; i < N; i++)
    {
        max += V[i];
        acc[i] = max;
    }
    int minIndex = V.begin() - min_element(V.begin(), V.end());
    int min = V[minIndex];
    int count = 0;
    vector<pair<int, int>> ranges;
    while (min + 1 <= max)
    {
        ranges.clear();
        int mid = ceil((min + max) / 2.0);
        int i = 0, j = 0;
        count = 0;
        while (i < N)
        {
            int price = acc[j] - (i == 0 ? 0 : acc[i - 1]);
            if (price <= mid)
            {
                count++;
                if (price == mid){
                    ranges.insert(ranges.begin(), {i, j});
                }
            }
            j++;
            if (j == N)
            {
                i++;
                j = i;
            }
        }
        if(count < K)
            min = mid;
        else if (count - ranges.size() + 1 > (size_t)K)
            max = mid;
        else
            break;
    }
    cout << ranges[count - K].first << ' ' << ranges[count - K].second << endl;
}