__int128_t atoint128_t(std::string const &in) {
	__int128_t res = 0;
	size_t i = 0;
	bool sign = false;
	if (in[i] == '-') {
		++i;
		sign = true;
	}
	if (in[i] == '+') {
		++i;
	}
	for (; i < in.size(); ++i) {
		const char c = in[i];
		if (not std::isdigit(c)) {
			throw std::runtime_error(std::string("Non-numeric character: ") + c);
		}
		res *= 10;
		res += c - '0';
	}
	if (sign) {
		res *= -1;
	}
	return res;
}


int Solution::compareVersion(string version1, string version2) {
	for (auto &ch : version1) {
		if (ch == '.') {
			ch = ' ';
		}
	}
	for (auto &ch : version2) {
		if (ch == '.') {
			ch = ' ';
		}
	}
	istringstream s1(version1), s2(version2);
	while (1) {
		string n1, n2;
		if (not(s1 >> n1)) {
			n1 = "0";
		}
		if (not(s2 >> n2)) {
			n2 = "0";
		}
		if (not s1 and not s2) {
			return 0;
		}
		__int128_t x = atoint128_t(n1), y = atoint128_t(n2);
		if (x < y) {
			return -1;
		}
		if (x > y) {
			return 1;
		}
	}
}
