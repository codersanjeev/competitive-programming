#include <bits/stdc++.h>
using namespace std;

long long a[100005];

int main()
{
	int n,skip=0,marks=0;
	long long x;
	scanf("%d%lld",&n,&x);
	for(int i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
		if(skip<=1)
		{
			if(a[i]<=x)
			{
				marks++;
			}
		else
		{
				skip++;
			}
		}
	}
	printf("%d\n",marks);
	return 0;
}
