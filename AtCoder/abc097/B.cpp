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
	// x <= N
	// x = b ^ p
	// b >= 1 and p >= 2
	// b = [1, 1000]
	// p = [2, 1000]
	set<int> st;
	int N;
	read(N);

	for (int b = 1; b <= 1000; b++) {
		for (int p = 2; p <= 1000; p++) {
			st.insert(pow(b, p));
		}
	}

	int ans = 1;

	for (const auto &ele : st) {
		if (ele <= N) ans = max(ans, ele);
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