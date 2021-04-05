#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int t;
	long n;
	map<long, long> cache;
	map<long, long> ansmap;
	cin >> t;
	while (t--) {
		cin >> n;
		long ans = INT_MIN;
		if (cache[n] != 0) {
			cout << ansmap[cache[n]] << "\n";
			continue;
		}
		long temp = INT_MIN;
		long index = 1;
		for (long x = 1; x <= n; x++) {
			long y = x;
			long count = 0;
			while (y != 1) {
				if (y % 2 == 0) {
					y /= 2;
				} else {
					y = 3 * y + 1;
				}
				count++;
			}
			if (count > temp) {
				temp = count;
				index = x;
			}
		}
		cache[n] = temp;
		ansmap[temp] = index;
		cout << ansmap[cache[n]] << "\n";
	}
	return 0;
}