class Solution {
  public:

	const vector<string> keypad = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
	vector<string> combinations;

	vector<string> letterCombinations(string digits) {
		if (digits.empty()) {
			return {};
		}
		letterCombinationsUtil("", digits);
		return combinations;
	}

	void letterCombinationsUtil(string combination, string digits) {
		if (digits.empty()) {
			combinations.push_back(combination);
			return;
		}
		int digit = digits[0] - '0';
		for (const auto &letter : keypad[digit]) {
			letterCombinationsUtil(combination + letter, digits.substr(1));
		}
	}

};