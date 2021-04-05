#include<bits/stdc++.h>
using namespace std;

map<long long, long long> mp;

long long amount(long long n){
    if(n == 0)
        return 0;
    if(mp[n] == 0){
        long long x = amount(n/2) + amount(n/3) + amount(n/4);
        if(x > n){
            mp[n] = x;
        }
        else{
            mp[n] = n;
        }
    }
    return mp[n];
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    long long n;
    while(cin >>n){
        cout <<amount(n) <<"\n";
    }
    return 0;
}