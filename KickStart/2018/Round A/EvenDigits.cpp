/****************************************************
*   Template for coding contests                    *
*   Author    :    Sanjeev Sharma                   *
*   Email     :    thedevelopersanjeev@gmail.com    *
*****************************************************/
#pragma GCC optimize ("O3")
#pragma GCC optimize("Ofast")
#pragma GCC optimize ("unroll-loops")
#pragma GCC optimize("no-stack-protector,fast-math")
#pragma GCC target ("sse4")
#pragma comment(linker, "/stack:200000000")

#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>

#define deb(x) cout << #x << " is " << x << "\n";

using namespace std;
using namespace __gnu_pbds;

const double PI = 2 * acos(0.0);
template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

long solve(long n) {
	// 1. extract digits of n into a vector
	vector<int> digits;
	while(n != 0) {
		digits.push_back(n % 10);
		n /= 10;
	}
	// reverse to get original order
	reverse(digits.begin(), digits.end());
	// find position of first odd digit
	long firstOdd = -1;
	n = digits.size();
	for(long i = 0; i < n; i++) {
		if(digits[i] % 2 == 1) {
			firstOdd = i;
			break;
		}
	}
	// check if odd number is not found
	if(firstOdd == -1) {
		// then, given number is already has all even digits
		return 0LL;
	}
	long modn = 0;
    for(int i = firstOdd; i < n; i++)
        modn = modn*10 + digits[i];
    long tarn = digits[firstOdd] - 1;
    for(long i = firstOdd+1; i < n; i++)
        tarn = tarn*10 + 8;
    if(digits[firstOdd] == 9)
        return modn - tarn;
    else{
        long tar = digits[firstOdd] + 1;
        for(long i = firstOdd+1; i < n; i++)
            tar *= 10;
        return min(modn - tarn, tar - modn);
    }
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int t;
	long n;
	cin >>t;
	for(int i = 1; i <= t; i++) {
		cin >>n;
		cout <<"Case #" <<i <<": " <<solve(n) <<"\n";
	}
	return 0;
}
