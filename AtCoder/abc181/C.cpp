#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("no-stack-protector")
#pragma GCC optimize("fast-math")
#pragma GCC optimize("trapv")
#pragma GCC target("sse4")

#include <bits/stdc++.h>
using namespace std;

#define deb(x) cout << #x << " is " << x << "\n"
#define int long long
#define mod 1000000007
#define PI acos(-1)

int maxPoints(vector<vector<int>>& Points) {
    int Result = 0;
    const auto Hash = [](const auto &p) { return p.first ? hash<double>()(round(1000000000. * p.second / p.first)) : 42; };
    const auto Equal = [](const auto &p1, const auto &p2) { return (size_t)(p1.second) * p2.first == (size_t)(p1.first) * p2.second; };
    unordered_map<pair<int, int>, int, decltype(Hash), decltype(Equal)> Counters(Points.size(), Hash, Equal);
    for(const vector<int> &Origin: Points) {
        Counters.clear(); int BestForOriging = 0, Duplicates = 0;
        for(const vector<int> &Point: Points) {
            if(Point[0] == Origin[0] && Point[1] == Origin[1]) {
                ++Duplicates;
                continue;
            }
            BestForOriging = max(BestForOriging, ++Counters[{Point[0] - Origin[0], Point[1] - Origin[1]}]);
        }
        Result = max(Result, BestForOriging + Duplicates);
    }
    return Result;
}

void solve() {
	int n, x, y;
	cin >> n;
	vector<vector<int>> arr;
	while (n--) {
		cin >> x >> y;
		vector<int> temp = {x, y};
		arr.push_back(temp);
	}
	int mx = maxPoints(arr);
	cout << (mx >= 3 ? "Yes" : "No");
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int tc = 1;
    // cin >> tc;
    while(tc--) {
        solve();
    }
    return 0;
}
