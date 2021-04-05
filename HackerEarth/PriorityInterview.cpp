#include<bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n, a, b;
	cin >>n;
	vector<int> m, f;
	while(n--){
		cin >>a >>b;
		if(a == 1)
			m.push_back(b);
		else
			f.push_back(b);
	}
	sort(m.begin(), m.end());
	reverse(m.begin(), m.end());
	sort(f.begin(), f.end());
	reverse(f.begin(), f.end());
	for(auto ele : f)
		cout <<ele <<" ";
	for(auto ele : m)
		cout <<ele <<" ";
	cout <<"\n";
	return 0;
}