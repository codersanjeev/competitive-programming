#include<bits/stdc++.h>
using namespace std;

int main(){
    string s;
    cin >>s;
    char* st = new char[s.size()+1];
    st[s.size()] = 0;
    memcpy(st, s.c_str(), s.size());
    int acc = 0;
    int y = s.size();
    for(int i=0; i<y; i++){
        int x = (int)st[i];
        x -= 96;
        acc += x;
    }
    cout <<acc <<endl;
    return 0;
}