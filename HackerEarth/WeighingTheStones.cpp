#include<bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int t, n, ele;
	cin >>t;
	while(t--){
		cin >>n;
		map<int, int> rupam, ankit;
		for(int i = 0; i < n; i++){
			cin >>ele;
			rupam[ele]++;
		}
		for(int i = 0; i < n; i++){
			cin >>ele;
			ankit[ele]++;
		}
		auto x = max_element(rupam.begin(), rupam.end(), 
			[](const pair<int, int> &p1, const pair<int, int> &p2){
				return p1.second <= p2.second;
			});
		auto y = max_element(ankit.begin(), ankit.end(), 
			[](const pair<int, int> &p1, const pair<int, int> &p2){
				return p1.second <= p2.second;
			});
		if(x->first > y->first)
			cout <<"Rupam\n";
		else if(x->first < y->first)
			cout <<"Ankit\n";
		else
			cout <<"Tie\n";
	}
	return 0;
}