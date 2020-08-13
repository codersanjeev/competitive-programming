#include <bits/stdc++.h>
using namespace std;

int main() 
{
	int t;
	long n,i,s,s1,s2;
	cin>>t;
	while(t--)
	{
	    cin>>n;
	    long a[n],b[n];
	    s=s1=s2=0;
	    for(i=0;i<n;i++)
	    cin>>a[i];
	    for(i=0;i<n;i++)
	    cin>>b[i];
	    for(i=0;i<n;i++)
	    {
	        if(s1==s2 && a[i]==b[i])
	        s+=a[i];
	        s1+=a[i];
	        s2+=b[i];
	    }
	    cout<<s<<endl;
	}
	
	
	
	return 0;
}