#include <iostream>
using namespace std;
int sum(int n)
{
    int s=0;
    while(n>0)
    {
        s=s+n%10;
        n=n/10;
    }
    return s;
}
int main() {
	
	int t,count=0,k;
	cin>>k;
	t=k-97;
	while(t<k)
	{
	    int m=sum(t);
	    int s=t+m+sum(m);
	   if(s==k)
	   count++;
	   t++;
	}
	 cout<<count<<endl;
	return 0;
}