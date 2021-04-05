#pragma GCC target("avx2")
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("Ofast")

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

auto speedup = []() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	return nullptr;
}();

void solve(int tc) {
	int n, m;
	read(n, m);
	int lo = 2 * n - 1;
	int hi = n * (n + 1) / 2;
	if (m < lo || m > hi) {
		write("-1\n");
		return;
	}
	set<pair<int, int>> ans;
	for (int i = 1; i < n; i++) {
		ans.insert({i, i + 1});
	}
	int diff = hi - m, key = n;
	while (diff > 0) {
		int newKey = max(1LL, key - diff - 1);
		ans.erase({key - 1, key});
		ans.insert({newKey, key});
		diff -= (key - newKey - 1);
		key--;
	}
	for (const auto &ele : ans) {
		write(ele.first, " ", ele.second, "\n");
	}
}

signed main() {
	int tc = 1;
	// read(tc);
	for (int curr = 1; curr <= tc; curr++) {
		solve(curr);
	}
	return 0;
}