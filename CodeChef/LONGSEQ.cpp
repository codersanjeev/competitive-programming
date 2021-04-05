#include<bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int t;
	cin >>t;
	while(t--){
		string s;
		cin >>s;
		map<char, int> freq;
		for(int i = 0; i < s.size(); i++)
			freq[s[i]]++;
		if(freq['1'] == 1 || freq['0'] == 1)
			cout <<"Yes\n";
		else
			cout <<"No\n";
	}
	return 0;
}