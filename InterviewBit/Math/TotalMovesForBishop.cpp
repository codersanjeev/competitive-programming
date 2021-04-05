int Solution::solve(int i, int j) {
	i--;
	j--;
	int ans = 0;
	int x = i, y = j;
	x--;
	y--;
	while (x >= 0 && y >= 0) {
		ans++;
		x--;
		y--;
	}
	x = i, y = j;
	x++;
	y++;
	while (x < 8 && y < 8) {
		ans++;
		x++;
		y++;
	}
	x = i, y = j;
	x++;
	y--;
	while (x < 8 && y >= 0) {
		ans++;
		x++;
		y--;
	}
	x = i, y = j;
	x--;
	y++;
	while (x >= 0 && y < 8) {
		ans++;
		x--;
		y++;
	}
	return ans;
}
