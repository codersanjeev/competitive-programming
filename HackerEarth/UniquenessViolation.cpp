#include <bits/stdc++.h>
using namespace std;
int main() {
    
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int T;
    cin>>T;
    while(T--)
    {
    	int N,M;
    	cin>>N;
    	int color[N];
    	for(int i=0;i<N;i++)
    		cin>>color[i];
    	int arr[N];
    	for(int i=0;i<N;i++)
    		cin>>arr[i];
    	int ans=0;
    	for(int i=0;i<N;)
    	{
    		int j=i;
    		int maxval=arr[i];
    		for(j=i;j<N;j++)
    			if(color[i]==color[j])
    				maxval=max(maxval,arr[j]);
    			else
    				break;
    		i=j;
    		ans+=maxval;
    	}
    	cout<<ans<<endl;
    }
}
