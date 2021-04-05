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
		stack<char> temp;
		for(int i = 0; i < s.size(); i++)
			temp.push(s[i]);
		while(temp.top() == '0')
			temp.pop();
		while(!temp.empty()){
			cout <<temp.top();
			temp.pop();
		}
		cout <<"\n";
	}
	return 0;
}