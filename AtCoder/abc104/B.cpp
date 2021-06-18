#include<bits/stdc++.h>
using namespace std;

int main() {
	string S;
	cin >> S;
	int N = S.size();
	// A*CCC...CC*
	bool ok = true;
	if (S[0] != 'A') ok = false;
	int cnt = 0;
	for (int i = 2; i < N - 1; i++) {
		if (S[i] == 'C') cnt++;
	}
	if (cnt != 1) ok = false;
	if (isupper(S[N - 1]) || isupper(S[1])) ok = false;
	if (ok == false) {
		cout << "WA";
		return 0;
	}
	for (int i = 2; i < N - 1; i++) {
		if (S[i] != 'C' && isupper(S[i])) ok = false;
	}
	cout << (ok ? "AC" : "WA");
	return 0;
}