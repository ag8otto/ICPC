#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <fstream>
#include <cstring>
using namespace std;
int main()
{

    // INPUT
    ifstream cin("input.txt");
    int num_cards;
    cin >> num_cards;
    vector<string> Cards(num_cards);
    for (int i = 0; i < num_cards; i++)
        cin >> Cards[i];
    string Order = "SWER";
    vector<string> perms;
    sort(Order.begin(), Order.end());
    do
    {
        perms.push_back(Order);
    } while (next_permutation(Order.begin(), Order.end()));

    // FORMAT
    int minErr = num_cards;
    for (auto s : perms)
    {
        vector<int> vals(num_cards);
        for (int i = 0; i < num_cards; i++)
        {
            size_t pos = s.find(Cards[i][0]);
            vals[i] = (pos == string::npos ? 5*num_cards : int(pos + 1) * num_cards) + stoi(Cards[i].substr(1));
        }
        vector<int> dp(num_cards, 1); // LIS più lunga che che termina in i
        
        for (int i = 0; i < num_cards; i++)
            for (int j = 0; j < i; j++)
                if(vals[j] < vals[i])
                    dp[i] = max(dp[i] , dp[j] + 1);
        
        minErr = min (minErr, num_cards - *max_element(dp.begin(), dp.end()));
    }

    cout << minErr << endl;
}

/** S W E R C
    51 42 34 41

    42 51 16 36 55 24 15 10 45 52
    1  2  1  2  3  2  1  1  3  4
**/