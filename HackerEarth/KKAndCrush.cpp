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
    int t, n, k, x;
    cin >>t;
    for(int c = 0; c < t; c++){
        cin >>n;
        vector<int> arr(n);
        for(int i = 0; i < n; i++)
            cin >>arr[i];
        sort(arr.begin(), arr.end());
        cin >>k;
        for(int temp = 0; temp < k; temp++){
            cin >>x;
            if(binary_search(arr.begin(), arr.end(), x))
                cout <<"Yes\n";
            else
                cout <<"No\n";
        }
    }
	return 0;
}