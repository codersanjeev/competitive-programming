#include<bits/stdc++.h>
using namespace std;

int main(){
    int n, x, y;
    cin >>n >>x;
    while(n--){
        cin >>y;
        if(y >= x){
            cout <<"YES" <<endl;
        }
        else{
            cout <<"NO" <<endl;
        }
    }
    return 0;
}