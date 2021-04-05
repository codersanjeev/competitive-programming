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
    string a, b;
    cin >>t;
    while(t--){
        cin >>a >>b;
        set<char> st;
        for(int i = 0; i < a.size(); i++)
            st.insert(a[i]);
        bool flag = false;
        for(int i = 0; i < b.size(); i++)
            if(st.find(b[i]) != st.end())
                flag = true;
        if(flag)
            cout <<"YES\n";
        else
            cout <<"NO\n";
    }
	return 0;
}