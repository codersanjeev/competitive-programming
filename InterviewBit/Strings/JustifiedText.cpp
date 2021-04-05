vector<string> Solution::fullJustify(vector<string> &words, int L) {
	vector<string> res;
	int k = 0, l = 0;
	for (int i = 0; i < words.size(); i += k) {
		for (k = l = 0; i + k < words.size() && l + words[i + k].size() <= L - k; k++) {
			l += words[i + k].size();
		}
		string tmp = words[i];
		for (int j = 0; j < k - 1; j++) {
			if (i + k >= words.size()) { tmp += " "; }
			else { tmp += string((L - l) / (k - 1) + (j < (L - l) % (k - 1)), ' '); }
			tmp += words[i + j + 1];
		}
		tmp += string(L - tmp.size(), ' ');
		res.push_back(tmp);
	}
	return res;
}
