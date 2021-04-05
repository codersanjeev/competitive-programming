#include<bits/stdc++.h>

long long getNumberOfPainters(vector<int> arr, long long k) {
	long long total = 0LL, cnt = 1LL;
	for (auto ele : arr) {
		total += ele;
		if (total > k) {
			total = ele;
			cnt++;
		}
	}
	return cnt;
}

int Solution::paint(int k, int time, vector<int> &board) {
	long long lo = (long long) * max_element(board.begin(), board.end());
	long long hi = (long long) accumulate(board.begin(), board.end(), 0LL);
	while (lo < hi) {
		long long mid = lo + (hi - lo) / 2LL;
		if (getNumberOfPainters(board, mid) <= k) {
			hi = mid;
		} else {
			lo = mid + 1;
		}
	}
	return (lo * time) % 10000003LL;
}
