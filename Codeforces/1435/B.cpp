#pragma GCC optimize("O3")
#pragma GCC target("sse4")

#include <bits/stdc++.h>

using namespace std;

#define deb(x) cout << #x << " is " << x << "\n"
#define int long long
#define mod 1000000007
#define PI acos(-1)

template <typename T>
using min_heap = priority_queue<T, vector<T>, greater<T>>;

template <typename T>
using max_heap = priority_queue<T>;

void solve(int tc) {
    int n, m;
    cin >> n >> m;
    vector<set<pair<int, int>>> indexesStore(n);
    vector<vector<int>> reverseSet(n, vector<int>(m, 0));
    vector<vector<int>> columnsArray(m, vector<int>(n, 0));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            int ele;
            cin >> ele;
            indexesStore[i].insert({ele, i});
            reverseSet[i][j] = ele;
        }
    }
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> columnsArray[i][j];
        }
    }
    vector<int> answer(n, 0);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            auto it = indexesStore[j].begin();
            if (indexesStore[j].find({columnsArray[0][i], it->second}) != indexesStore[j].end())
                answer[i] = it->second;
        }
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cout << reverseSet[answer[i]][j] << " ";
        }
        cout << "\n";
    }
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int tc = 1;
    cin >> tc;
    for (int curr = 1; curr <= tc; curr++) solve(curr);
    return 0;
}