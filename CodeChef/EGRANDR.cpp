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
		int arr[n];
		for(int i = 0; i < n; i++)
			cin >>arr[i];
		int s = 0;
		bool hasScholarship = true, hasFive = false;
		for(int i = 0; i < n; i++){
			s += arr[i];
			if(arr[i] == 5)
				hasFive = true;
			if(arr[i] <= 2)
				hasScholarship = false;
		}
		double avg = (1.0 * s) / n;
		if(avg < 4.0)
			hasScholarship = false;
		if(hasScholarship && hasFive)
			cout <<"Yes\n";
		else
			cout <<"No\n";
	}
	return 0;
}