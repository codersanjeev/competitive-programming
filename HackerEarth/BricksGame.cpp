#include<bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, motu, patlu, i;
    bool flag = true;
    cin >>n;
    i = 1;
    while(n > 0){
        patlu = i;
        n -= patlu;
        flag = true;
        if(n < 0)
            break;
        motu = i*2;
        n -= motu;
        flag = false;
        i++;
    }
    if(flag){
        cout <<"Patlu" <<endl;
    }
    else{
        cout <<"Motu" <<endl;
    }
    return 0;
}