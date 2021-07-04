#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> coins;
    int coin = 1, ans = 0;
    for (int i = 1; i <= 10; ++i) {
        coin *= i;
        for (int j = 1; j <= 100; ++j) {
            coins.push_back(coin);
        }
    }
    reverse(begin(coins), end(coins));
    for (const auto &ele : coins) {
        if (ele <= n) {
            n -= ele;
            ++ans;
        }
    }
    cout << ans;
    return 0;
}