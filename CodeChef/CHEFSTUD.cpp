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
		string s1 = "";
		for(int i = 0; i < s.size(); i++){
			if(s[i] == '*')
				s1.append("*");
			else if(s[i] == '>')
				s1.append("<");
			else
				s1.append(">");
		}
		int ans = 0;
		for(int i = 0; i < s1.size(); i++){
			if(s1[i] == '>' && s1[i+1] == '<')
				ans++;
		}
		cout <<ans <<"\n";
	}
	return 0;
}