#include<bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int t;
	cin >>t;
	while(t--){
		string ele;
		vector<string> ing1;
		for(int i = 0; i < 4; i++){
			cin >>ele;
			ing1.push_back(ele);
		}
		int found = 0;
		for(int i = 0; i < 4; i++){
			cin >>ele;
			if(find(ing1.begin(), ing1.end(), ele) != ing1.end())
				found++;
		}
		if(found >= 2)
			cout <<"similar\n";
		else
			cout <<"dissimilar\n";
	}
	return 0;
}