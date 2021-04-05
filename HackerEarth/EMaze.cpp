#include<bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string s;
    cin >>s;
    int x, y;
    x = 0;
    y = 0;
    for(char& c : s){
        if(c == 'L')
            x--;
        else if(c == 'R')
            x++;
        else if(c == 'U')
            y++;
        else
            y--;
    }
    cout <<x <<" " <<y;
    return 0;
}