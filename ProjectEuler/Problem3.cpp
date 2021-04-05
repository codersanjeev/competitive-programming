#include <bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin >> t;
	while (t != 0) {
		long long n;
		cin >> n;
		long long div = 2LL;
		while (div <= floor(sqrt(n))) {
			if (n % div == 0LL) {
				n /= div;
			} else {
				div++;
			}
		}
		cout << n << endl;
		t--;
	}
	return 0;
}