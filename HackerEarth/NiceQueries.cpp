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
    int n, q, t, x;
    cin >>n >>q;
    map<int, int> mp;
    while(q--){
        cin >>t >>x;
        bool done = false;
        if(t == 1){
            mp[x] = 1;
        }
        else{
            auto it = mp.lower_bound(x);
                if(it != mp.end()){
                    cout <<it->first <<"\n";
                }
                else
                {
                        cout <<-1 <<"\n";
                }
                
        }
    }
	return 0;
}