#define _CRT_SECURE_NO_WARNINGS
#pragma comment(linker, "/stack:64000000")
#include <string>
#include <vector>
#include <map>
#include <list>
#include <iterator>
#include <cassert>
#include <set>
#include <queue>
#include <iostream>
#include <sstream>
#include <stack>
#include <deque>
#include <cmath>
#include <memory.h>
#include <cstdlib>
#include <cstdio>
#include <cctype>
#include <algorithm>
#include <utility>
#include <time.h>
#include <complex>
using namespace std;
#define FOR(i, a, b) for(int i=(a);i<(b);i++)
#define RFOR(i, b, a) for(int i=(b)-1;i>=(a);--i)
#define FILL(A,value) memset(A,value,sizeof(A))
#define ALL(V) V.begin(), V.end()
#define SZ(V) (int)V.size()
#define PB push_back
#define MP make_pair
#define Pi 3.14159265358979
#define x0 ikjnrmthklmnt
#define y0 lkrjhkltr
#define y1 ewrgrg
typedef long long Int;
typedef unsigned long long UInt;
typedef vector<int> VI;
typedef pair<int, int> PII;
typedef pair<Int, Int> PLL;
typedef pair<double, double> PDD;
typedef complex<double> base;
const int INF = 1000000000;
const int BASE = 1000000007;
const int MAX = 100007;
const int ADD = 1000000;
const int MOD = 1000000007;
const int CNT = 800;
int main()
{
    //freopen("in.txt", "r", stdin);
    //freopen("distance.in",  "r", stdin);
    //freopen("distance.out", "w", stdout);
    //freopen("out.txt" , "w" , stdout);
	int res = 0;
	int n , l;
	cin >> n >> l;
	assert(n >= 1 && n <= 10);
	FOR(test,0,n)
	{
		string s;
		cin >> s;
		assert(SZ(s) >= 1 && SZ(s) <= l);
		bool ok = 0;
		int n = SZ(s);
		FOR(l1,0,n)
			FOR(r1,l1,n)
				FOR(l2,r1 + 1 , n)
					FOR(r2 , l2 , n)
					{
						string t = s;
						reverse(t.begin() + l1 , t.begin() + r1 + 1);
						reverse(t.begin() + l2 , t.begin() + r2 + 1);
						string tt = t;
						reverse(ALL(tt));
						if (tt == t)
							ok = 1;
					}
		res += ok;
	}
	cout << res << endl;
    return 0;
}