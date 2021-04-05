#include<bits/stdc++.h>
using namespace std;

long long func(long long n){
    long long power = 1, shift = 0;
    while(true){
        if(((n>>shift)&1)%2 == 0)
            break;
        shift++;
        power *= 2;
    }
    return (n+power);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    long long t, n;
    cin >>t;
    while(t--){
        cin >>n;
        cout <<func(n) <<"\n";
    }
    return 0;
}