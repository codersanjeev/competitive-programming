string Solution::fractionToDecimal(int A, int B) {
	long long num = (long long) A;
	long long den = (long long) B;
	if (A == 0) {
		return "0";
	}
	string ans;
	if (num < 0 ^ den < 0) {
		ans += "-";
	}
	num = abs(num);
	den = abs(den);
	ans += to_string(num / den);
	if (num % den == 0) {
		return ans;
	}
	ans += ".";
	unordered_map<long long, long long> mp;
	for (long long rem = num % den; rem > 0; rem %= den) {
		if (mp[rem] != 0) {
			ans.insert(mp[rem], 1, '(');
			ans += ")";
			break;
		}
		mp[rem] = ans.size();
		rem *= 10;
		ans += to_string(rem / den);
	}
	return ans;
}
