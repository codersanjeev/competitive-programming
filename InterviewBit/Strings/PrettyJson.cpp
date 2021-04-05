vector<string> Solution::prettyJSON(string A) {
	int rows = 0, braces = 1;
	vector<string> ans(1, "");
	int n = A.size();
	for (int i = 0; i < n; i++) {
		auto ele = A[i];
		switch (ele) {
		case ' ' :
			continue;
			break;
		case '{' :
		case '[' :
			if (braces == 1 && rows == 0) {
				ans[rows] += A[i];
			} else {
				ans.push_back("");
				ans[++rows] += string(braces, '\t');
				ans[rows] += A[i];
				++braces;
			}
			ans.push_back("");
			ans[++rows] += string(braces, '\t');
			break;
		case '}' :
		case ']' :
			if (braces > 1) {
				ans.push_back("");
				ans[++rows] += string(braces - 1, '\t');
				ans[rows] += A[i];
				--braces;
			} else {
				ans.push_back("");
				ans[++rows] += A[i];
				--braces;
			}
			break;
		case ',' :
			ans[rows] += A[i];
			if (A[i + 1] == '{' || A[i + 1] == '[') {
				continue;
			} else {
				ans.push_back("");
				ans[++rows] += string(braces, '\t');
			}
			break;
		case ':' :
			ans[rows] += ele;
			if (A[i + 1] == '{' || A[i + 1] == '[') {
				ans.push_back("");
				ans[++rows] = string(braces, '\t');
				ans[rows] += A[++i];
				++braces;
				if (A[i + 1] != '{' && A[i + 1] != '[') {
					ans.push_back("");
					ans[++rows] += string(braces, '\t');
					ans[rows] += A[++i];
				}
			}
			break;
		default :
			ans[rows] += ele;
			break;
		}
	}
	return ans;
}