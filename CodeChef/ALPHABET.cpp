#include<bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	string s;
	cin >>s;
	set<char> alphabets;
	for(int i = 0; i < s.size(); i++)
		alphabets.insert(s[i]);
	int n;
	cin >>n;
	while(n--){
		string word;
		cin >>word;
		bool flag = true;
		for(int i = 0; i < word.size(); i++){
			if(!alphabets.count(word[i])){
				flag = false;
				break;
			}
		}
		if(flag)
			cout <<"Yes\n";
		else
			cout <<"No\n";
	}
	return 0;
}