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
    int t, n, q, ele;
    cin >>t;
    while(t--){
        unordered_map<int, int> freq;
        cin >>n >>q;
        while(n--){
            cin >>ele;
            freq[ele]++;
        }
        while(q--){
            cin >>ele;
            cout <<freq[ele] <<"\n";
        }
    }
	return 0;
}