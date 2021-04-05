#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int N, K;
	cin >>N >>K;
	vector<int> x(N);
	for(int i=0; i<N; i++)
		cin >>x[i];
	vector<int> last_set(30,INT_MIN);
	vector<int> ans(N);
	for(int i=0;i<N;i++){
		for(int j=0;j<30;j++){
			if((x[i]>>j)&1)
			    last_set[j] = i;
			if(i<=K+last_set[j])
			    ans[i]|=(1<<j);
		}
	}
	for(auto i:ans)
	    cout <<i <<" ";
    return 0;
}