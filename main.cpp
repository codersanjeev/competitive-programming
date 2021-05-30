#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("no-stack-protector")
#pragma GCC optimize("fast-math")

#include <bits/stdc++.h>

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

#define deb(x) cout << #x << " is " << x << "\n"
#define int long long
#define MOD 1000000007LL
#define PI acos(-1)

template <typename T>
using min_heap = priority_queue<T, vector<T>, greater<T>>;

template <typename T>
using max_heap = priority_queue<T>;

template <class T>
using ordered_set = tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;

template <typename... T>
void read(T &...args) {
	((cin >> args), ...);
}

template <typename... T>
void write(T &&...args) {
	((cout << args), ...);
}

template <typename T>
void readContainer(T &t) {
	for (auto &e : t) {
		read(e);
	}
}

template <typename T>
void writeContainer(T &t) {
	for (const auto &e : t) {
		write(e, " ");
	}
	write("\n");
}

int maximumGap(vector<int> &nums) {
	int n = nums.size();
	if (n < 2) return 0;
	int mx = *max_element(nums.begin(), nums.end());
	int mn = *min_element(nums.begin(), nums.end());
	double bucket = double(mx - mn) / double(n - 1);
	vector<int> maxElement(n, INT_MIN);
	vector<int> minElement(n, INT_MAX);
	for (int i = 0; i < n; ++i) {
		int index = (nums[i] - mn) / bucket;
		maxElement[index] = max(maxElement[index], nums[i]);
		minElement[index] = min(minElement[index], nums[i]);
	}
	int ans = 0, previous = maxElement[0];
	for (int i = 1; i < n; ++i) {
		if (minElement[i] == INT_MAX) continue;
		ans = max(ans, minElement[i] - previous);
		previous = maxElement[i];
	}
	return ans;
}

void solve(int tc) {
}

signed main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int tc = 1;
	read(tc);
	for (int curr = 1; curr <= tc; ++curr) {
		solve(curr);
	}
	return 0;
}