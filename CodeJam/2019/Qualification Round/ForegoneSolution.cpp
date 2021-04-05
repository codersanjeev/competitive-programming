/**
 *  @author Sanjeev
 */
#include<bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    string s, ans, ans2;
    cin >>t;
    for(int i = 1; i <= t; i++){
        cin >>s;
        ans = "";
        ans2 = "";
        bool found = false;
        for(int j = 0; j < s.size(); j++){
            ans += s[j];
            if(s[j] == '4'){
                found = true;
                ans[j] = '3';
                ans2 += '1';
            }
            else if(found){
                ans2 += '0';
            }
        }
        cout <<"Case #" <<i <<": " <<ans <<" " <<ans2 <<"\n";
    }
    return 0;
}