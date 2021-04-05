const int mod = 1e9 + 7;
vector<vector<int>> nCr(1001, vector<int>(1001));
vector<int> pw(1001);

void preprocessing(int n) {
	for (int i = 0; i <= n; i++)	{
		for (int j = 0; j <= i; j++) {
			if (j == 0 || j == i) {
				nCr[i][j] = 1;
			} else {
				nCr[i][j] = (nCr[i - 1][j - 1] + nCr[i - 1][j]) % mod;
			}
		}
	}
	pw[0] = 1;
	pw[1] = 1;
	for (int i = 2; i <= n; i++) {
		pw[i] = (pw[i - 1] * 2) % mod;
	}
}

int Solution::solve(int n, vector<int> &vis) {
	int m = vis.size();
	preprocessing(n);
	sort(vis.begin(), vis.end());
	long long temp;
	long long ans = 1;
	long long cnt = 0;
	for (int i = 0; i < m; i++) {
		if (i == 0) {
			temp = vis[i] - 1;
		} else {
			temp = vis[i] - vis[i - 1] - 1;
			ans = (ans * pw[temp]) % mod;
		}
		cnt += temp;
		ans = (ans * nCr[cnt][temp]) % mod;
	}
	cnt += (n - vis[m - 1]);
	ans = (ans * nCr[cnt][n - vis[m - 1]]) % mod;
	return ans;
}
