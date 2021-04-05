#include<bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int t;
	string s1, s2;
	cin >>t;
	while(t--){
		cin >>s1 >>s2;
		int max = 0, min = 0;
		for(int i = 0; i < s1.size(); i++){
			if(s1[i] != s2[i] && s1[i] != '?' && s2[i] != '?'){
				max++;
				min++;
			}
			else if(s1[i] == '?' || s2[i] == '?'){
				max++;
			}
		}
		cout <<min <<" " <<max <<"\n";
	}
	return 0;
}