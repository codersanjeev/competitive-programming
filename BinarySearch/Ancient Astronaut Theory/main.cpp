bool solve(string dictionary, string s) {
	int n = dictionary.size(), i = 0;
	if (n == 0) {
		return true;
	}
	for (const auto &ch : s) {
		if (dictionary.find(ch) != string::npos) {
			while (i < n && dictionary[i] != ch) {
				i++;
			}
			if (i >= n || dictionary[i] != ch) {
				return false;
			}
		}
	}
	return true;
}