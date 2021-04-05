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
		vector<int> arr;
		for(auto ele : freq)
			arr.push_back(ele.second);
		bool flag = false;
		for(auto ele : arr){
			if(ele == accumulate(arr.begin(), arr.end(), 0) - ele){
				flag = true;
				break;
			}
		}
		if(flag)
			cout <<"YES\n";
		else
			cout <<"NO\n";
	}
	return 0;
}