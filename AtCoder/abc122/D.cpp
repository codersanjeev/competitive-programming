#include <bits/stdc++.h>

#define F first 
#define S second
#define PB push_back

using namespace std;

typedef long long LL;
typedef pair<int, int> PII;
typedef priority_queue<int> HEAP;
typedef priority_queue<int, vector<int>, greater<int> > RHEAP;

const int N = 110, M = 5, mod = 1e9 + 7;

int n;
int f[N][M][M][M];

int main()
{
	cin >> n;
	f[0][0][0][0] = 1;
	
	for (int i = 0; i < n; i ++ )
		for (int a = 0; a <= 4; a ++ )
			for (int b = 0; b <= 4; b ++ )
				for (int c = 0; c <= 4; c ++ )
					for (int j = 1; j <= 4; j ++ )
					{
						if (b == 1 && c == 2 && j == 3) continue;
						if (b == 1 && c == 3 && j == 2) continue;
						if (b == 2 && c == 1 && j == 3) continue;
						if (a == 1 && b == 2 && j == 3) continue;
						if (a == 1 && c == 2 && j == 3) continue;
						f[i + 1][b][c][j] = (f[i + 1][b][c][j] + f[i][a][b][c]) % mod;
					}
	
	int res = 0;
	for (int i = 1; i <= 4; i ++ )
		for (int j = 1; j <= 4; j ++ )
			for (int k = 1; k <= 4; k ++ )
				res = (res + f[n][i][j][k]) % mod;
	cout << res << endl;
    return 0;
}