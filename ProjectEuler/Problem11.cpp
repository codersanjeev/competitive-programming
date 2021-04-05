#include <bits/stdc++.h>
using namespace std;

int x[] = {0, 0, 0, 1, 2, 3, 1, 2, 3, 1, 2, 3};
int y[] = {1, 2, 3, 1, 2, 3, 0, 0, 0, -1, -2, -3};

bool isvalid(int r, int c) { return (r < 20 && r >= 0 && c >= 0 && c < 20); }

int main() {
	int grid[20][20];
	for (int i = 0; i < 20; ++i) {
		for (int j = 0; j < 20; ++j) {
			cin >> grid[i][j];
		}
	}
	long long sum = 0, tempsum = 0;
	for (int i = 0; i < 20; ++i) {
		for (int j = 0; j < 20; ++j) {
			for (int s = 0; s < 12; ++s) {
				if (s % 3 == 0) {
					sum = max(sum, tempsum);
					tempsum = grid[i][j];
				}
				if (isvalid(i + x[s], j + y[s])) {
					tempsum *= grid[i + x[s]][j + y[s]];
				}
			}
			sum = max(sum, tempsum);
		}
	}
	cout << sum;
	return 0;
}