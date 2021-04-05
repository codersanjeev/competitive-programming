#include<bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int t, n, m;
	cin >>t;
	while(t--){
		cin >>n >>m;
		vector<int> a(n), b(m);
		for(int i = 0; i < n; i++)
			cin >>a[i];
		for(int i = 0; i < m; i++)
			cin >>b[i];
		int ans = 0;
		sort(b.begin(), b.end());
		for(auto ele : a){
			if(binary_search(b.begin(), b.end(), ele))
				ans++;
		}
		cout <<ans <<"\n";
	}
	return 0;
}