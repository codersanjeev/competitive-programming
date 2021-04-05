#include<bits/stdc++.h>
using namespace std;

long long solve(long long x){
    if(x < 9) 
        return x;
    return x%9 + 10*solve(x/9);
}

int main(){
    long long n;
    while(cin >>n){
        cout <<solve(n) <<endl;
    }
    return 0;
}