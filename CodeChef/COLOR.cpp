#include<bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int t, n;
	cin >>t;
	while(t--){
		cin >>n;
		string s;
		cin >>s;
		map<char, int> freq;
		for(int i = 0; i < s.size(); i++)
			freq[s[i]]++;
		if(freq.size() == 2){
			int ans = INT_MAX;
			for(auto ele : freq){
				if(ans > ele.second)
					ans = ele.second;
			}
			cout <<ans <<"\n";
		}
		else if(freq.size() == 3){
			vector<int> eles;
			for(auto ele : freq)
				eles.push_back(ele.second);
			sort(eles.begin(), eles.end());
			cout <<eles[0]+eles[1] <<"\n";
		}
		else{
			cout <<"0\n";
		}
	}
	return 0;
}