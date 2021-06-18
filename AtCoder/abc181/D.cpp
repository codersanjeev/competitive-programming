#include <bits/stdc++.h>
using namespace std;

int main() {
	string s;
	cin >> s;
  	if (s.size() == 1) {
		cout << (stoi(s) % 8 == 0 ? "Yes" : "No"); 
      	return 0;
    }
  	if (s.size() == 2) {
		if (stoi(s) % 8 == 0) {
			cout << "Yes";
			return 0;
		}
		swap(s[0], s[1]);
		if (stoi(s) % 8 == 0) {
			cout << "Yes";
			return 0;
		}
		cout << "No";
		return 0;
    }
	vector<int> cnt(10, 0);
	for (const auto &ch : s) {
		cnt[ch - '0']++;
	}
	bool ok = false;
	for (int i = 112; i < 1000; i += 8) {
    	vector<int> c = cnt;
    	for (char x : to_string(i)) c.at(x - '0')--;
    	if (all_of(c.begin(), c.end(), [](int x) { 
    		return x >= 0; 
    	})) {
    		ok = true;
    	}
	}
	cout << (ok ? "Yes" : "No");
	return 0;
}