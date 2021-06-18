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
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

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

int extgcd(int a, int b, int &x, int &y) {
	if (b == 0) {
		x = 1;
		y = 0;
		return a;
	}

	int d = extgcd(b, a % b, y, x);
	y -= a / b * x;
	return d;
}

int binpow(int a, int p) {
	if (gcd(a, p) != 1)
		return -1;

	int x, y;
	extgcd(a, p, x, y);

	x %= p;

	if (x < 0)
		x += p;

	return x;
}

void solve(int tc) {
	int N, S, K;
	read(N, S, K);
	// (K.x + S) % N = 0
	// (K.x) % N = (-S) % N
	int C = (N - S);
	int G = gcd(gcd(K, C), N);
	K /= G;
	C /= G;
	N /= G;
	int x = binpow(K, N);

	if (x == -1) {
		write(-1, "\n");

	} else {
		write((x * C) % N, "\n");
	}
}

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
// #ifndef ONLINE_JUDGE
// 	freopen("input.txt", "r", stdin);
// 	freopen("output.txt", "w", stdout);
// #endif
	int tc = 1;
	read(tc);

	for (int curr = 1; curr <= tc; curr++) solve(curr);

	return 0;
}