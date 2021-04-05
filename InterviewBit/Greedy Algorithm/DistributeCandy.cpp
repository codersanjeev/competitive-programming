#include<bits/stdc++.h>

int Solution::candy(vector<int> &children) {
	int n = children.size();
	vector<int> ans(n, 1);
	for (int i = 1; i < n; i++) {
		if (children[i] > children[i - 1]) {
			ans[i] = ans[i - 1] + 1;
		}
	}
	for (int i = n - 2; i >= 0; i--) {
		if (children[i] > children[i + 1]) {
			ans[i] = max(ans[i], ans[i + 1] + 1);
		}
	}
	return accumulate(ans.begin(), ans.end(), 0);
}
