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
void read(T &... args) {
	((cin >> args), ...);
}

template <typename... T>
void write(T &&... args) {
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

const int N = 1e5 + 1;
vector<int> cost(N, 0);
bitset<100010> isPrime;
vector<int> primeNumbers;

void sieve(int _sieve_size) {
	isPrime.set();
	isPrime[0] = isPrime[1] = 0;
	for (int i = 2; i <= _sieve_size; i++) {
		if (isPrime[i]) {
			for (int j = i * i; j <= _sieve_size; j += i) {
				isPrime[j] = 0;
			}
			primeNumbers.push_back(i);
		}
	}
}

int primeFactors(int n) {
	map<int, int> mp;
	int idx = 0, p = primeNumbers[idx];
	while (p * p <= n) {
		while (n % p == 0) {
			n /= p;
			mp[p]++;
		}
		p = primeNumbers[++idx];
	}
	if (n != 1) {
		mp[n]++;
	}
	int ans = 0;
	for (const auto &ele : mp) {
		ans += ele.second;
	}
	return ans;
}

void precomputeCost() {
	for (int i = 2; i < N; i++) {
		cost[i] = primeFactors(i);
	}
}

int minCostPath(const vector<vector<int>> &arr, int i, int j, int n, int m, vector<vector<int>> &dp) {
	if (i < 0 || j < 0 || i >= n || j >= m) {
		return INT_MAX;
	}
	if (i == n - 1 && j == m - 1) {
		return arr[i][j];
	}
	if (dp[i][j] != -1) {
		return dp[i][j];
	}
	int x = minCostPath(arr, i + 1, j, n, m, dp);
	int y = minCostPath(arr, i, j + 1, n, m, dp);
	dp[i][j] = arr[i][j] + min(x, y);
	return dp[i][j];
}

void solve(int tc) {
	int n, m;
	read(n, m);
	vector<vector<int>> arr(n, vector<int>(m));
	vector<vector<int>> dp(n, vector<int>(m, -1));
	for (int i = 0; i < n; i++) {
		readContainer(arr[i]);
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			arr[i][j] = cost[arr[i][j]];
		}
	}
	write(minCostPath(arr, 0, 0, n, m, dp), "\n");
}

signed main() {
	int tc = 1;
	read(tc);
	sieve(N);
	precomputeCost();
	for (int curr = 1; curr <= tc; curr++) {
		solve(curr);
	}
	return 0;
}