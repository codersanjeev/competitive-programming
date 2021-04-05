#pragma GCC optimize("O3")
#pragma GCC target("sse4")

#include <bits/stdc++.h>

using namespace std;

#define deb(x) cout << #x << " is " << x << "\n"
#define int long long
#define mod 1000000007
#define PI acos(-1)

template <typename T>
using min_heap = priority_queue<T, vector<T>, greater<T>>;

template <typename T>
using max_heap = priority_queue<T>;

template <typename... T>
void read(T &... args) {
	((cin >> args), ...);
}

template <typename... T>
void write(T &&... args) {
	((cout << args), ...);
}

void solve(int tc) {
	int x1, y1, x2, y2;
	read(x1, y1, x2, y2);
	if (x1 == x2 && y1 == y2) {
		write("SECOND\n");
		return;
	}
	vector<int> dx = { -1, -1, -1, 0, 1, 1, 1, 0};
	vector<int> dy = { -1, 0, 1, 1, 1, 0, -1, -1};
	for (int i = 0; i < 8; i++) {
		int nx = x1 + dx[i];
		int ny = y1 + dy[i];
		if (nx == x2 && ny == y2) {
			write("FIRST\n");
			return;
		}
	}
	write("DRAW\n");
}

int32_t main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int tc = 1;
	read(tc);
	for (int curr = 1; curr <= tc; curr++) { solve(curr); }
	return 0;
}