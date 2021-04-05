#include<bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string s;
    cin >>s;
    char* st = new char[s.size()+1];
    char x[] = "111111";
    char y[] = "000000";
    st[s.size()] = '0';
    memcpy(st, s.c_str(), s.size());
    if(strstr(st, x) || strstr(st, y)){
        cout <<"Sorry, sorry!";
    }
    else{
        cout <<"Good luck!";
    }
    return 0;
}