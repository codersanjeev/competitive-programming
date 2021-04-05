bool solve(string a, string b) {
	vector<int> freq(26, 0);
	for (const auto &ele : a) {
		freq[ele - 'a']++;
	}
	for (const auto &ele : b) {
		freq[ele - 'a']--;
	}
	return all_of(freq.begin(), freq.end(), [](const int &x) {
		return x == 0;
	});
}