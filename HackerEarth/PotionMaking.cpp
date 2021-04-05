#include<bits/stdc++.h>
using namespace std;

int main(){
    string s;
    cin >>s;
    char* st = new char[s.size()+1];
    st[s.size()] = 0;
    memcpy(st, s.c_str(), s.size());
    int acc = 0;
    for(int i=0; i<10; i++){
        int x = st[i] - '0';
        acc += (x*(i+1));
    }
    if(acc%11 == 0){
        cout <<"Legal ISBN" <<endl;
    }
    else{
        cout <<"Illegal ISBN" <<endl;
    }
    return 0;
}