#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int t, n, k;
	string s;
	cin >> t;
	while (t--) {
		cin >> n >> k >> s;
		vector<int> digits(n);
		for (int i = 0; i < n; i++) {
			digits[i] = s[i] - '0';
		}
		long ans = INT_MIN;
		long i = 0;
		while (i <= n - k) {
			long count = 1, temp = 1;
			for (long j = i; count <= k; j++, count++) {
				temp *= digits[j];
			}
			ans = max(ans, temp);
			i++;
		}
		cout << ans << "\n";
	}
	return 0;
}