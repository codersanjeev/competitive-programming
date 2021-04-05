#include<bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int t;
	cin >>t;
	while(t--){
		int cost[26];
		for(int i = 0; i < 26; i++)
			cin >>cost[i];
		string s;
		cin >>s;
		int freq[26] = {0};
		for(int i = 0; i < s.size(); i++)
			freq[s[i]-'a']++;
		int ans = 0;
		for(int i = 0; i < 26; i++)
			if(freq[i] == 0)
				ans += cost[i];
		cout <<ans <<"\n";
	}
	return 0;
}