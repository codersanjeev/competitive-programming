#include<bits/stdc++.h>
using namespace std;

vector<int> intersection(vector<int> &v1, vector<int> &v2){
    vector<int> v3;
    set_intersection(v1.begin(),v1.end(), v2.begin(), v2.end(), back_inserter(v3));
    return v3;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int t, n, m, k;
	cin >>t;
	while(t--){
		cin >>n >>m >>k;
		vector<int> a(m), b(k), u(n);
		for(int i = 1; i <= n; i++)
			u[i-1] = i;
		for(int i = 0; i < m; i++)
			cin >>a[i];
		for(int i = 0; i < k; i++)
			cin >>b[i];
		auto ansA = intersection(a, b);
		int ansB = 0;
		for(int i = 1; i <= n; i++)
			if(find(a.begin(), a.end(), i) == a.end() && find(b.begin(), b.end(), i) == b.end())
				ansB++;
		cout <<ansA.size() <<" " <<ansB <<"\n";
	}
	return 0;
}