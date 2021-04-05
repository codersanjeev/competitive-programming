/**
 * Template for Contests
 *
 *  @author Sanjeev
 */
#include <bits/stdc++.h>
using namespace std;

long long lcm(long long a, long long b){
	return (a * b) / __gcd(a, b);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    long long n, a, b;
    cin >>n >>a >>b;
    cout <<(n/a) + (n/b) - (n/lcm(a, b));
    return 0;
}