int solve(string animals, string dinosaurs) {
	unordered_map<char, int> mp;
	for (const auto &ele : animals) {
		mp[ele]++;
	}
	int ans = 0;
	set<char> uniqueDinosaurs(dinosaurs.begin(), dinosaurs.end());
	for (const auto &ele : uniqueDinosaurs) {
		ans += mp[ele];
	}
	return ans;
}