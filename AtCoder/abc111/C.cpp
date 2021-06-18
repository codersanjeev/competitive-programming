#include <bits/stdc++.h>

#define REP(i, n) for(int (i)=0;(i)<(n);++(i))
#define MOD 1000000007

using namespace std;

typedef long long ll;

bool compare_by_b(pair<int, int> a, pair<int, int> b) {
    if(a.second != b.second){
        return a.second > b.second;
    }else{
        return a.first < b.first;
    }
}

int main()
{
    int n;
    cin >> n;
    map<int, int> countNumMap[2];
    REP(i, n)
    {
        int t;
        cin >> t;
        if (countNumMap[i % 2].find(t) == countNumMap[t % 2].end())
        {
            countNumMap[i % 2][t] = 1;
        }
        else
        {
            countNumMap[i % 2][t]++;
        }
        
    }

    vector<pair<int, int>> countPair[2];
    for (int i = 0; i <= 1; ++i)
    {
        for (auto iter = countNumMap[i].begin(); iter != countNumMap[i].end(); ++iter)
        {
            countPair[i].push_back(make_pair(iter->first, iter->second));
        }
        sort(countPair[i].begin(), countPair[i].end(), compare_by_b);
    }

    int ans;
    if (countPair[0][0].first != countPair[1][0].first)
    {
        ans = n / 2 - countPair[0][0].second + n / 2 - countPair[1][0].second;
    }
    else
    {
        int numEven = countPair[0].size() == 1 ? n / 2 : n / 2 - countPair[0][1].second;
        int numOdd = countPair[1].size() == 1 ? n / 2 : n / 2 - countPair[1][1].second;
        ans = min(n / 2 - countPair[0][0].second + numOdd, numEven + n / 2 - countPair[1][0].second);
    }

    cout << ans << endl;
}
