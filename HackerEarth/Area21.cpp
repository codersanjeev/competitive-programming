#include<bits/stdc++.h>
#define md 1000000007
using namespace std;
 
typedef long long int lint;
lint sv[1000007];

int main(){
 
	sv[0]=sv[1]=1;
	for(lint i=0;i*i<1000007;i++)
	{
		if(sv[i]==0){
		for(lint j=2*i;j<=1000007;j+=i)
			sv[j]=1;
	     }
	}
	lint n,q;
	cin>>n>>q;
	lint arr[n+1]={0},cm[n+1]={0};
	for(lint i=1;i<=n;i++)
		cin>>arr[i];
	for(lint i=1;i<=n;i++)
	{
		if(sv[arr[i]]==0)
			cm[i]=cm[i-1]+1;
		else
			cm[i]=cm[i-1];
	}
	while(q--){
		lint l,r;
		cin>>l>>r;
		cout<<cm[r]-cm[l-1]<<endl;
	}
}