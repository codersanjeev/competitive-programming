#include<bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    string s;
    cin >>s;
    int x = 0, y = 0;
    for(int i=0; i<s.size(); i++){
        if(s[i] == 'L')
            x--;
        else if(s[i] == 'R')
            x++;
        else if(s[i] == 'U')
            y++;
        else
            y--;
    }
    cout <<x <<" " <<y;
    return 0;
}