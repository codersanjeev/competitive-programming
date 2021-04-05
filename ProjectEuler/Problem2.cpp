#include <bits/stdc++.h>
using namespace std;
#define max 4000001

long cache[max] = {0};

long fib(long x) {
	if (x == 1 || x == 2) {
		return x;
	} else if (cache[x] != 0) {
		return cache[x];
	} else {
		cache[x] = fib(x - 1) + fib(x - 2);
	}
	return cache[x];
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	long t, n;
	cin >> t;
	while (t--) {
		cin >> n;
		long ans = 0;
		for (long i = 1; fib(i) <= n; i++) {
			if (fib(i) % 2 == 0) {
				ans += fib(i);
			}
		}
		cout << ans << "\n";
	}
	return 0;
}