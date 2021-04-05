#include <bits/stdc++.h>
using namespace std;
#define lli long long int

int main(){
std::ios_base::sync_with_stdio(false);
cin.tie(NULL);
lli i,t,n;
cin>>t;
while(t--)
{

cin>>n;
if(n==1||n==2)
	{
		cout<<"1\n";continue;
	}
lli ctr=1;
i=1;
while((ctr+=i*(lli)pow(2,i))<=n)
{
i++;
}
lli dist=  i*(lli)pow(2,i) - (ctr - n) +1 ;
if(dist>=(2*i-1))
	dist=2*i-1;
else dist =  2*(i-1)-1>dist?2*(i-1)-1:dist;
cout<<dist<<"\n";
}
return 0;
}