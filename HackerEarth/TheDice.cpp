#include<bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    string s;
    cin >>s;
    int ans = s.size();
    for(int i = 0; i < s.size(); i++)
        if(s[i] == '6')
            ans = ans - 1;
    if(s[s.size() - 1] == '6')
        cout <<-1;
    else
        cout <<ans;
    return 0;
}