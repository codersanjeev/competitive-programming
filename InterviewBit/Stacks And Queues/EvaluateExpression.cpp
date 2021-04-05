bool isOperator(string s) {
	return s == "+" || s == "-" || s == "*" || s == "/";
}

int Solution::evalRPN(vector<string> &arr) {
	stack<int> st;
	for (auto ele : arr) {
		if (isOperator(ele)) {
			int x = st.top();
			st.pop();
			int y = st.top();
			st.pop();
			swap(x, y);
			if (ele == "+") {
				st.push(x + y);
			} else if (ele == "-") {
				st.push(x - y);
			} else if (ele == "*") {
				st.push(x * y);
			} else if (ele == "/") {
				st.push(x / y);
			}
		} else {
			st.push(stoi(ele));
		}
	}
	return st.top();
}
