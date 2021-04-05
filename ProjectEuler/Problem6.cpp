#include<bits/stdc++.h>
using namespace std;

long solve(long n) {
	return abs(pow(n * (n + 1) / 2, 2) - n * (n + 1) * (2 * n + 1) / 6);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	long t, n;
	cin >> t;
	while (t--) {
		cin >> n;
		cout << solve(n) << "\n";
	}
	return 0;
}
