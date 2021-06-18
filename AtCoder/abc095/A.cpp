#include <bits/stdc++.h>
using namespace std;

int main() {
	string S;
	cin >> S;
	int ans = 700;

	for (const auto &ch : S) {
		if (ch == 'o') ans += 100;
	}

	cout << ans;
	return 0;
}