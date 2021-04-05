#include<bits/stdc++.h>
using namespace std;

int main(){
    long long t;
    cin >>t;
    string s;
    while(t--){
        cin >>s;
        char* st = new char[s.size()+1];
        st[s.size()] = '0';
        memcpy(st, s.c_str(), s.size());
        long long answer = 0;
        for(unsigned long i=0; i<s.size(); i++){
            if(st[i] == 'A' || st[i] == 'E' || st[i] == 'I' ||
            st[i] == 'O' || st[i] == 'U' || st[i] == 'a' ||
            st[i] == 'e' || st[i] == 'i' || st[i] == 'o' || st[i] == 'u'){
                answer += (i+1)*(s.size()-i);
            }
        }
        cout <<answer <<endl;
    }
    return 0;
}