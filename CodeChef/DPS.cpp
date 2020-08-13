#include <iostream>
using namespace std;

int main() {
	
	int t;
	cin>>t;
	cin>>ws;
	while(t--)
	{
	    string s;
	    cin>>s;
	    int i,l=s.length();
	    int a[123]={0};
	    for(i=0;i<l;++i)
	    a[s[i]]++;
	    int c1=0;
	    for(i=97;i<=122;++i)
	    c1+=a[i]%2;
	    if(l%2==1 && c1<=3)
	    {
	        cout<<"DPS\n";
	    }
	    else if((c1==1 && l%2==0)||(c1==2 && l%2==0))
	    cout<<"DPS\n";
	    else 
	    cout<<"!DPS\n";
	}
	return 0;
}
