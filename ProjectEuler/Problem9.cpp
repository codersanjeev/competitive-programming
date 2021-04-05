#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int t, n;
	cin >> t;
	while (t--) {
		cin >> n;
		int ans = INT_MIN;
		for (int i = 1; i <= n / 3; i++) {
			int j = (n * n - 2 * n * i) / (2 * n - 2 * i);
			int k = n - i - j;
			if (i * i + j * j == k * k) {
				ans = max(i * j * k, ans);
			}
		}
		if (ans != INT_MIN) {
			cout << ans << "\n";
		} else {
			cout << "-1\n";
		}
	}
	return 0;
}