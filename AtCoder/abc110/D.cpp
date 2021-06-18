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

const int mxN = 2e5 + 5;
vector<int> fact(mxN), invfact(mxN);

int binpow(int a, int b, int m) {
	a %= m;
	int res = 1LL;

	while (b > 0) {
		if (b & 1)
			res = res * a % m;

		a = a * a % m;
		b >>= 1;
	}

	return res;
}

int nCr(int n, int r) {
	int N = fact[n];
	int D = (invfact[n - r] * invfact[r]) % MOD;
	return (N * D) % MOD;
}

void solve(int tc) {
	fact[0] = 1LL;
	invfact[0] = binpow(fact[0], MOD - 2, MOD);

	for (int i = 1; i < mxN; i++) {
		fact[i] = (i * fact[i - 1]) % MOD;
		invfact[i] = binpow(fact[i], MOD - 2, MOD);
	}

	int N, M;
	read(N, M);
	int ans = 1LL;

	for (int i = 2; i * i <= M; i++) {
		int curr = 0LL;

		while (M % i == 0) {
			M /= i;
			curr++;
		}

		ans = mod(ans * nCr(curr + N - 1, curr));
	}

	if (M > 1) {
		int curr = 1LL;
		ans = mod(ans * nCr(curr + N - 1, curr));
	}

	write(ans);
}

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int tc = 1;
	// read(tc);

	for (int curr = 1; curr <= tc; curr++) solve(curr);

	return 0;
}