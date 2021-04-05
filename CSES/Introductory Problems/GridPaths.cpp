/****************************************************
*   Template for coding contests                    *
*   Author    :    Sanjeev Sharma                   *
*   Email     :    thedevelopersanjeev@gmail.com    *
*****************************************************/
#pragma GCC optimize ("O3")
#pragma GCC optimize("Ofast")
#pragma GCC optimize ("unroll-loops")
#pragma GCC optimize("no-stack-protector")
#pragma GCC optimize("fast-math")
#pragma GCC target ("sse4")
#pragma comment(linker, "/stack:200000000")

#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>

using namespace __gnu_pbds;
using namespace std;

#define deb(x) cout << #x << " is " << x << "\n";
#define int long long
#define mod 1000000007

const double PI = 2 * acos(0.0);
const long long INF = 1e18L + 5;
template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

template<class... Args>
auto create(size_t n, Args&&... args) {
	if constexpr(sizeof...(args) == 1)
		return vector(n, args...);
	else
		return vector(n, create(args...));
}

template<typename... T>
void read(T&... args) {
	((cin >> args), ...);
}

template<typename... T>
void write(T&&... args) {
	((cout << args), ...);
}

const int N = 7;
bool visited[N][N];
vector<int> dx = {0, 1, 0, -1};
vector<int> dy = { -1, 0, 1, 0};

int findAnswer(string &str, int cur = 0, int y = 0, int x = 0) {
	if (y == N - 1 && x == 0) return (cur == (N * N - 1));
	if (((y + 1 == N || (visited[y - 1][x] && visited[y + 1][x])) && x - 1 >= 0 && x + 1 < N && !visited[y][x - 1] && !visited[y][x + 1]) || ((x + 1 == N || (visited[y][x - 1] && visited[y][x + 1])) && y - 1 >= 0 && y + 1 < N && !visited[y - 1][x] && !visited[y + 1][x]) || ((y == 0 || (visited[y + 1][x] && visited[y - 1][x])) && x - 1 >= 0 && x + 1 < N && !visited[y][x - 1] && !visited[y][x + 1]) || ((x == 0 || (visited[y][x + 1] && visited[y][x - 1])) && y - 1 >= 0 && y + 1 < N && !visited[y - 1][x] && !visited[y + 1][x]))
		return 0;
	visited[y][x] = true;
	int res = 0;
	for (int i = 0; i < 4; ++i) {
		if ((str[cur] == 'U' && i != 0) || (str[cur] == 'R' && i != 1) || (str[cur] == 'D' && i != 2) || (str[cur] == 'L' && i != 3))
			continue;
		int _y = y + dy[i], _x = x + dx[i];
		if (_y >= 0 && _x >= 0 && _y < N && _x < N && !visited[_y][_x])
			res += findAnswer(str, cur + 1, _y, _x);
	}
	visited[y][x] = false;
	return res;
}

void solve() {
	string s;
	cin >> s;
	cout << findAnswer(s);
}

int32_t main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
// #ifndef ONLINE_JUDGE
// 	freopen("input.txt", "r", stdin);
// 	freopen("output.txt", "w", stdout);
// #endif
	solve();
	return 0;
}
