bool areMatchingPair(char x, char y) {
	return (x == '(' && y == ')') || (x == '{' && y == '}') || (x == '[' && y == ']');
}

bool isOpening(char ch) {
	return ch == '(' || ch == '{' || ch == '[';
}

int Solution::isValid(string s) {
	// () , {} , []
	stack<char> st;
	for (auto ele : s) {
		if (isOpening(ele)) {
			st.push(ele);
		} else {
			if (st.empty() || !areMatchingPair(st.top(), ele)) {
				return 0;
			} else {
				st.pop();
			}
		}
	}
	return st.empty();
}
