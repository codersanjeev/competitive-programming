#include<bits/stdc++.h>
using namespace std;

int main(){
    string s;
    cin >>s;
    char* st = new char[s.size()+1];
    st[s.size()] = '0';
    memcpy(st, s.c_str(), s.size());
    int ans = 0;
    for(unsigned int i=0; i<s.size(); i++){
        ans += (int)(st[i] - 96);
    }
    cout <<ans;
    return 0;
}