
#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	vector<long> arr;
	bool prime[1000001];
	memset(prime, true, sizeof(prime));
	for (long p = 2; p * p <= 1000000; p++) {
		if (prime[p]) {
			for (long i = p * p; i <= 1000000; i += p) {
				prime[i] = false;
			}
		}
	}
	for (long i = 2; i <= 1000000; i++) {
		if (prime[i]) {
			arr.push_back(i);
		}
	}
	long t, n;
	cin >> t;
	while (t--) {
		cin >> n;
		cout << arr[n - 1] << "\n";
	}
	return 0;
}