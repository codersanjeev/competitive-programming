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
	int N;
	string S;
	read(N, S);

	int ans = 0;

	for (int i = 1; i < N; i++) {
		string A = S.substr(0, i);
		string B = S.substr(i);
		set<char> sta(A.begin(), A.end());
		set<char> stb(B.begin(), B.end());
		int curr = 0;

		for (const auto &ch : sta) {
			if (stb.count(ch) > 0) {
				curr++;
			}
		}

		ans = max(ans, curr);
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