#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;

// input data
int N, L;
vector<pair<int, int>> PD;

int maxDayi(vector<pair<int, int>>& PD, int index, int remaining_days) {
    if (PD.empty()) return -1;

    int count_noD = count_if(PD.begin(), PD.end(), [](const pair<int, int>& p) {
        return p.second == -1;
    });
    if (count_noD <= remaining_days) {
        int max_value = -1;
        auto it = PD.end();
        for (auto iter = PD.begin(); iter != PD.end(); ++iter) {
            if (iter->second >= index && iter->first > max_value) {
                max_value = iter->first;
                it = iter;
            }
        }
        if (it != PD.end()) {
            PD.erase(it);
            return max_value;
        }
    }
    int max_value = PD.front().first;
    PD.erase(PD.begin());
    return max_value;
}

void print(vector<pair<int, int>>){
    for (const auto& p : PD) {
        cout << p.first << ' ' << p.second << endl;
    }
    cout << endl;
}

void remove_Delem(vector<pair<int, int>>& PD, int index) {
    PD.erase(remove_if(PD.begin(), PD.end(), [index](const pair<int, int>& p) {
        return p.second <= index && p.second != -1;
    }), PD.end());
}

int main() {
//  uncomment the following lines if you want to read/write from files
    ifstream cin("input1.txt");
    ofstream cout("output.txt");
    cin >> N >> L;
    PD.resize(N);
    for (int i=0; i<N; i++)
        cin >> PD[i].first >> PD[i].second;

    sort(PD.begin(), PD.end(), [](const pair<int, int>& a, const pair<int, int>& b) {
       return a.first > b.first;
    });

    int r_pages = 0;
    for (int i = 0; i < L && !PD.empty(); i++) {
        print(PD);
        int p = maxDayi(PD, i, L-i);
        if (p > 0) r_pages += p;
        cout  << "Pagine Lette: " << p << endl;
        remove_Delem(PD, i);
    }
    cout << r_pages << endl; // print the result
    return 0;
}
