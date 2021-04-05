#include <bits/stdc++.h>
using namespace std;

long solve(long a, long n) {
	return n * (n + 1) / 2;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	long t, n;
	cin >> t;
	while (t--) {
		cin >> n;
		long x = (n - 1) / 3;
		long y = (n - 1) / 5;
		long z = (n - 1) / 15;
		cout << 3 * solve(3, x) + 5 * solve(5, y) - 15 * solve(15, z) << "\n";
	}
	return 0;
}