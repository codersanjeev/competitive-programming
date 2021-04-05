/**
 * Template for Contests
 *
 *  @author Sanjeev
 */
#include <bits/stdc++.h>
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
		int n = s.size();
		bool flag = true;
		for(int i = 0; i < n-1; i += 2){
			if((s[i] == 'A' && s[i+1] == 'A') || (s[i] == 'B' && s[i+1] == 'B'))
				flag = false;
		}
		cout << ((flag)?("yes\n"):("no\n"));
	}
    return 0;
}