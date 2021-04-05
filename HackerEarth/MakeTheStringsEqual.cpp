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

bool solve(const string &S, const string &T, int N) {
	string a = S, b = T;
	sort(a.begin(), a.end());
	sort(b.begin(), b.end());
	if (a != b) {
		return false;
	}
	for (int i = 0; i < N - 1; i++) {
		if (S[i] == S[i + 1] || T[i] == T[i + 1]) {
			return true;
		}
	}
	a = "", b = "";
	for (int i = 0; i < N; i++) {
		if (S[i] != T[i]) {
			a += S[i];
			b += T[i];
		}
	}
	int n = a.size(), ops = 0;
	unordered_map<char, int> mp;
	for (int i = 0; i < n; i++) {
		mp[a[i]] = i;
	}
	for (int i = 0; i < n; i++) {
		int j = mp[b[i]];
		ops += (j - i);
		while (j > i) {
			swap(a[j], a[j - 1]);
			swap(mp[a[j]], mp[a[j - 1]]);
			j--;
		}
	}
	return ops % 2 == 0;
}

void solve(int tc) {
	int N;
	string S, T;
	read(N, S, T);
	if (solve(S, T, N)) {
		write("YES\n");
	} else {
		write("NO\n");
	}
}

signed main() {
	int tc = 1;
	read(tc);
	for (int curr = 1; curr <= tc; curr++) {
		solve(curr);
	}
	return 0;
}