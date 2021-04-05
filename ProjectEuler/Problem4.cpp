#include<bits/stdc++.h>
using namespace std;

bool checkPalindrome(int n) {
	string x = to_string(n);
	string y = x;
	reverse(y.begin(), y.end());
	return x == y;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	vector<int> all;
	for (int i = 100; i <= 999; i++) {
		for (int j = 100; j <= 999; j++) {
			if (checkPalindrome(i * j)) {
				all.push_back(i * j);
			}
		}
	}
	sort(all.begin(), all.end());
	int t, n;
	cin >> t;
	while (t--) {
		cin >> n;
		auto it = lower_bound(all.begin(), all.end(), n);
		cout << *(it - 1) << "\n";
	}
	return 0;
}