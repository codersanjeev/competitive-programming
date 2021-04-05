int N = 1e6 + 1;
vector<int> prime(N);

void buildSieve() {
	prime[0] = prime[1] = 1;
	for (int i = 2; i < N; i++)
		prime[i] = i;
	for (int i = 2; (i * i) <= N; i++) {
		if (prime[i] == i) {
			for (int j = i * i; j < N; j += i) {
				if (prime[j] == j) {
					prime[j] = i;
				}
			}
		}
	}
}

int findAnswer(int n) {
	unordered_map<int, int> mp;
	while (n > 1) {
		mp[prime[n]]++;
		n /= prime[n];
	}
	int ans = 1;
	for (auto ele : mp) {
		ans *= (ele.second + 1);
	}
	return ans;
}

vector<int> Solution::solve(vector<int> &arr) {

	buildSieve();
	vector<int> ans;
	for (auto ele : arr)
		ans.push_back(findAnswer(ele));
	return ans;

}
