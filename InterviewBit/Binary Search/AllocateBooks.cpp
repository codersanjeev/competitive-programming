#include<bits/stdc++.h>

bool isPossibleToAllocateBooks(vector<int> &books, int m, int minPages) {
	int students = 1;
	int currPages = 0;
	for (auto ele : books) {
		if (ele > minPages) {
			return false;
		} else if (currPages + ele > minPages) {
			students++;
			currPages = ele;
			if (students > m) {
				return false;
			}
		} else {
			currPages += ele;
		}
	}
	return true;
}

int Solution::books(vector<int> &books, int m) {
	int n = books.size();
	if (n < m) {
		return -1;
	}
	int lo = 0;
	int hi = accumulate(books.begin(), books.end(), 0);
	int ans = INT_MAX;
	while (lo <= hi) {
		int mid = lo + (hi - lo) / 2;
		if (isPossibleToAllocateBooks(books, m, mid)) {
			ans = min(ans, mid);
			hi = mid - 1;
		} else {
			lo = mid + 1;
		}
	}
	return ans;
}