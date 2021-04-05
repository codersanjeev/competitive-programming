#include<bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t, n;
    cin >>t;
    string s;
    while(t--){
        cin >>n;
        cin >>s;
        char* st = new char[s.size()+1];
        st[s.size()] = '0';
        memcpy(st, s.c_str(), s.size());
        int count = 0;
        for(int i=0; i<s.size(); i++){
            if(st[i] == '0')
                count++;
        }
        cout <<count <<endl;
    }
    return 0;
}