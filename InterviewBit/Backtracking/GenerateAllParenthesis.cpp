vector<string> ans;
string curr;

void generateParenthesisUtil(int n, int open, int closed) {
	if (closed == n) {
		ans.push_back(curr);
		return;
	} else {
		if (open > closed) {
			curr += ")";
			generateParenthesisUtil(n, open, closed + 1);
			curr.pop_back();
		}
		if (open < n) {
			curr += "(";
			generateParenthesisUtil(n, open + 1, closed);
			curr.pop_back();
		}
	}
}

vector<string> Solution::generateParenthesis(int n) {
	curr = "";
	ans.clear();
	generateParenthesisUtil(n, 0, 0);
	sort(ans.begin(), ans.end());
	return ans;
}
