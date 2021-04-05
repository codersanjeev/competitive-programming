#include<bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int t;
	string s;
	cin >>t;
	while(t--){
		cin >>s;
		map<char, int> freq;
		for(int i = 0; i < s.size(); i++)
			freq[s[i]]++;
		cout <<min(freq['a'], freq['b']) <<"\n";
	}
	return 0;
}