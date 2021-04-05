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
	int n;
	cin >>n;
	int c[n], t[n];
	for(int i = 0; i < n; i++)
		cin >>c[i];
	for(int i = 0; i < n; i++)
		cin >>t[i];
	int t_min=1000001,a_min=1000001,at_min=1000001;
    for(int i=0;i<n;i++)
    {
        if(t[i]==1)
         t_min=min(c[i],t_min);
        else
            if(t[i]==2)
                a_min=min(c[i],a_min);
            else
                at_min=min(at_min,c[i]);
    }

    if((t_min+a_min)<=at_min)
        cout<<t_min+a_min;
    else
        cout<<at_min;

    return 0;
}