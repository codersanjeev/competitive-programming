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
	int N, M, K;
	read(N, M);
	vector<pair<int, int>> conditions(M);
	for (int i = 0; i < M; i++) {
		read(conditions[i].first, conditions[i].second);
	}
	read(K);
	vector<pair<int, int>> people(K);
	for (int i = 0; i < K; i++) {
		read(people[i].first, people[i].second);
	}
	int ans = 0;
	for (int mask = 0; mask < (1 << K); mask++) {
		vector<int> balls(N + 1, 0);
		for (int i = 0; i < K; i++) {
			if (mask & (1 << i)) {
				balls[people[i].first]++;
			} else {
				balls[people[i].second]++;
			}
		}
		int curr = 0;
		for (int i = 0; i < M; i++) {
			if (balls[conditions[i].first] > 0 && balls[conditions[i].second] > 0) {
				curr++;
			}
		}
		ans = max(ans, curr);
	}
	write(ans);
}

signed main() {
	int tc = 1;
	// read(tc);
	for (int curr = 1; curr <= tc; curr++) {
		solve(curr);
	}
	return 0;
}