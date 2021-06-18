#include <bits/stdc++.h>
using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define Max(x,y,z) max(x,max(y,z))
#define Min(x,y,z) min(x,min(y,z))
#define fr(i,s,e) for(i=s;i<e;i++)
#define rf(i,s,e) for(i=s-1;i>=e;i--)
#define pb push_back
#define eb emblace_back
#define mp make_pair

typedef long long ll;
typedef unsigned int uint;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;
typedef vector<int> vi;
typedef vector<long long> vll;
typedef vector<pair<long long,long long> > vpll;
typedef vector<vector<ll> > vvll;

#define PI 3.141592653589793
#define MOD 1000000007

template<typename T> T gcd(T a,T b) { if(a==0) return b; return gcd(b%a,a); }
template<typename T> T pow(T a,T b, ll m){T ans=1; while(b>0){ if(b%2==1) ans=(ans*a)%m; b/=2; a=(a*a)%m; } return ans%m; }

int main()
{
	IOS;
	ll n;
	cin>>n;
	vpll v(n);
	for(ll i=0;i<n;i++)
	{
		cin>>v[i].first;
		v[i].second=i+1;
	}
	sort(v.begin(),v.end());
	ll curindex=v[n-1].second;
	ll tempsp=v[n-1].second;
	while(tempsp>1)
	{
		cout<<endl;
		tempsp--;
	}
	cout<<v[n-1].first;
	ll count=1;
	ll st=v[n-1].second+1;
	for(ll i=n-2;i>=0;i--)
	{
		if(v[i].second<curindex)
		{
			
			count++;
			cout<<" "<<v[i].first;
		}
		else
		{
			cout<<endl;
			count=0;
			curindex=v[i].second;
			while(curindex>st)
			{
				cout<<endl;
				curindex--;
			}
			cout<<v[i].first;
			curindex=v[i].second;
			st=v[i].second+1;
		}
	}
	return 0;
}
