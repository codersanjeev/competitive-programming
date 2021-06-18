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

const int N = 1001;
vector<vector<int>> dp(N, vector<int>(N, 0));

int solveUtil(const vector<int> &A, const vector<int> &B, int i, int j) {
	if (i == -1 && j == -1) {
		return 0;
	}

	if (i == -1) {
		return j + 1;
	}

	if (j == -1) {
		return i + 1;
	}

	if (dp[i][j] != 0) {
		return dp[i][j];
	}

	int x = solveUtil(A, B, i - 1, j) + 1;
	int y = solveUtil(A, B, i, j - 1) + 1;
	int z = solveUtil(A, B, i - 1, j - 1) + (A[i] != B[j]);

	// write(x, "\t", y, "\t", z, "\n");

	return dp[i][j] = min({x, y, z});
}

void solve(int tc) {
	int n, m;
	read(n, m);
	vector<int> arr(n), brr(m);
	readContainer(arr);
	readContainer(brr);
	write(solveUtil(arr, brr, n - 1, m - 1));
}

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int tc = 1;
	// read(tc);

	for (int curr = 1; curr <= tc; curr++) solve(curr);

	return 0;
}