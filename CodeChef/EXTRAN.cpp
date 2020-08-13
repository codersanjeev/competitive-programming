#include <bits/stdc++.h>
#define ll long long int 
using namespace std;

int main() {
	
	int t;
	cin>>t;
	while(t--)
	{
	    int i;
	    int n;
	    cin>>n;
	    ll a[n];
	    for(i=0;i<n;++i)
	    {
	        cin>>a[i];
	    }
	    sort(a,a+n);
	    for(i=0;i<=n-3;++i)
	    {
	        if(a[i]==a[i+1])
	        {
	        cout<<a[i]<<"\n";
	        break;
	        }
	        else if(a[i+1]==a[i+2])
	        {
	            cout<<a[i+1]<<"\n";
	            break;
	        }
	        else if((abs(a[i]-a[i+1])>1)&&(abs(a[i+1]-a[i+2])==1))
	        {
	            cout<<a[i]<<"\n";
	            break;
	        }
	        else if((abs(a[i]-a[i+1])==1)&&(abs(a[i+1]-a[i+2])>1))
	        {
	            cout<<a[i+2]<<"\n";
	            break;
	        }
	    }
	}
	return 0;
}
