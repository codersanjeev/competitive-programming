#include <bits/stdc++.h>
#define ll long long int
#define ul unsigned long long int
#define vl vector<long long int>
#define pb push_back
#define ii pair<int, int>
#define vii vector<ii>
#define mod 1000000007
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;
int main()
{
	IOS;
	int t;
	cin>>t;
	while(t--)
	{
		int n,i;
		cin>>n;
		ll a[n];
		for(i=0;i<n;i++)
		cin>>a[i];
		sort(a,a+n);
		int f=1,count=0;
		for(i=0;i<n;i++)
		{
			if(a[i]>count)
			{
				f=-1;
				break;
			}
			else if(a[i]<=count)
			{
				count++;
			}
		}
		cout<<count<<"\n";
	}
	
	
	return 0;
}