#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main() {
	ll t;
	cin>>t;
	while(t--)
	{
	   char a[51];
	   int p[51],c=0;
	   cin>>a;
	   for(int i=0;a[i]!='\0';i++)
	   {
	       if(a[i]=='.')
	       p[i]=0;
	       else
	       p[i]=1;
	   }
	   for(int i=0;a[i]!='\0';i++)
	   {
	       if(a[i]!='.')
	       {
	           for(int j=1;j<=((int)a[i]-48);j++)
	               p[i+j]=p[i+j]+1;
	           for(int j=((int)a[i]-48);j>=1;j--)
	           {
	            if((i-j)>=0)
	            {
	               p[i-j]=p[i-j]+1; 
	            }
	           }
	       }
	   }
	   for(int i=0;a[i]!='\0';i++)
	   {
	       if(p[i]>=2)
	       {
	           c=1;
	           break;
	       }
	   }
	   if(c==0)
	   cout<<"safe"<<endl;
	   else
	   cout<<"unsafe"<<endl;
	}
	return 0;
}
