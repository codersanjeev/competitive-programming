class Solution {
  public:
	int shortestSubarray(vector<int> &A, int K) {
		int N = A.size(), ans = N + 1;
		deque<int> q;
		for (int i = 0; i < N; i++) {
			if (i > 0) {
				A[i] += A[i - 1];
			}
			if (A[i] >= K) {
				ans = min(ans, i + 1);
			}
			while (!q.empty() && A[i] - A[q.front()] >= K) {
				ans = min(ans, i - q.front());
				q.pop_front();
			}
			while (!q.empty() && A[i] <= A[q.back()]) {
				q.pop_back();
			}
			q.push_back(i);
		}
		return ans == N + 1 ? -1 : ans;
	}
};