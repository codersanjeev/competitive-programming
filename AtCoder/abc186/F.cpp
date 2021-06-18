#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("no-stack-protector")
#pragma GCC optimize("fast-math")
#pragma GCC optimize("trapv")
#pragma GCC target("sse4")

#include <bits/stdc++.h>

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

#define deb(x) cout << #x << " is " << x << "\n"
#define int long long
#define MOD 1000000007LL
#define mod(x) (x % MOD + MOD) % MOD
#define PI acos(-1)

template <typename T>
using min_heap = priority_queue<T, vector<T>, greater<T>>;

template <typename T>
using max_heap = priority_queue<T>;

template <class T>
using ordered_set = tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;

template <typename... T>
void read(T &... args) {
	((cin >> args), ...);
}

template <typename... T>
void write(T &&... args) {
	((cout << args), ...);
}

template <typename T>
void readContainer(T &t) {
	for (auto &e : t) read(e);
}

template <typename T>
void writeContainer(T &t) {
	for (const auto &e : t) write(e, " ");

	write("\n");
}

void solve(int tc) {
	int H, W, M;
	read(H, W, M);
	vector<int> X(M), Y(M);
	vector<int> hLimit(H + 1, W), wLimit(W + 1, H);

	for (int i = 0; i < M; i++) {
		read(X[i], Y[i]);
		hLimit[X[i]] = min(hLimit[X[i]], Y[i] - 1);
		wLimit[Y[i]] = min(wLimit[Y[i]], X[i] - 1);
	}

	int ans = 0;

	for (int i = 1; i <= hLimit[1]; i++) {
		ans += wLimit[i];
	}

	vector<pair<int, int>> arr;

	for (int i = 2; i <= wLimit[1]; i++) {
		arr.push_back({hLimit[i], i});
	}

	sort(arr.begin(), arr.end());
	ordered_set<int> st;
	int r = 0;

	for (const auto &ele : arr) {
		while (r < ele.first && r < hLimit[1]) {
			st.insert(wLimit[++r]);
		}

		ans += (hLimit[ele.second] - st.size() + st.order_of_key(ele.second - 1));
	}

	write(ans);
}

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
// #ifndef ONLINE_JUDGE
// 	freopen("input.txt", "r", stdin);
// 	freopen("output.txt", "w", stdout);
// #endif
	int tc = 1;
	// read(tc);

	for (int curr = 1; curr <= tc; curr++) solve(curr);

	return 0;
}