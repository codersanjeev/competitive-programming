#include<bits/stdc++.h>

int main() {
	using namespace std;
	ios_base::sync_with_stdio(false), cin.tie(nullptr);
	int N; cin >> N;
	int ans = 0;
	set<int64_t> pref;
	int64_t cur_pref = 0;
	pref.insert(cur_pref);
	while (N--) {
		int a; cin >> a;
		cur_pref += a;
		if (pref.count(cur_pref)) {
			ans++;
			pref = set<int64_t>({cur_pref - a});
		}
		pref.insert(cur_pref);
	}
	cout << ans << '\n';

	return 0;
}
