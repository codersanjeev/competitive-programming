/**
 * Template for Contests
 *
 *  @author Sanjeev
 */
#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define ld long double
#define pb push_back
 
ll mod = 1000000007;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
	 cin>>n;
	 int x[n];
	 int y[n];
	 for (int i = 0; i < n; ++i)
	 {
	 	cin>>x[i]>>y[i];
	 }
 
	 sort(x,x+n);
	 sort(y,y+n);
 
	 ll ansx,ansy;
 
	 if(n%2 != 0)
	 {
	 	int midx = x[(n-1)/2];
	 	int midy = y[(n-1)/2];
	 	ll xx = 0;
	 	ll yy = 0;
	 	for (int i = 0; i < n; ++i)
	 	{
	 		xx += abs(midx - x[i]);
	 		yy += abs(midy - y[i]);
	 	}
	 	ansx = xx;
	 	ansy = yy;
	 }
	 else
	 {
	 	int midx1 = x[n/2];
	 	int midx2 = x[(n/2)-1];
	 	int midy1 = y[n/2];
	 	int midy2 = y[(n/2)-1];
	 	ll xx1=0,xx2=0,yy1=0,yy2=0;
	 	for (int i = 0; i < n; ++i)
	 	{
	 		xx1 += abs(midx1 - x[i]);
	 		yy1 += abs(midy1 - y[i]);
	 		xx2 += abs(midx2 - x[i]);
	 		yy2 += abs(midy2 - y[i]);
	 	}
 
	 	ansx = min(xx1,xx2);
	 	ansy = min(yy1,yy2);
 
 
	 }
 
	 cout<<min(ansx,ansy)<<"\n";
	return 0;
    return 0;
}