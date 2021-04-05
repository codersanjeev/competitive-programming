#include<cstdio>
#include<iostream>
using namespace std;
int nx[110];
int main()
{
	//freopen("in.txt","r",stdin);
	int n,k;
	string s;
	cin>>n>>k>>s;
	for(int i=1,j=0;i<s.size();i++)
	{
		while(j&&s[i]!=s[j])j=nx[j-1];
		if(s[i]==s[j])j++;
		nx[i]=j;
	}
	int len=s.size()-nx[n-1];
	for(int i=1;i<k;i++)
	    cout<<s.substr(0,len);
	cout<<s;
	return 0;
}
