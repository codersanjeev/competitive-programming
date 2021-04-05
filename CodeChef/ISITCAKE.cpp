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
	int t, ele;
	cin >>t;
	while(t--){
		int ans = 0;
		for(int i = 0; i < 100; i++){
			cin >>ele;
			if(ele <= 30)
				ans++;
		}
		if(ans >= 60)
			cout <<"yes\n";
		else
			cout <<"no\n";
	}    
    return 0;
}