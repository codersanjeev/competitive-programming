#include<bits/stdc++.h>
using namespace std;

int checkPrime(int n){
    int divisor = 1; 
    while (n / divisor >= 10) 
        divisor *= 10; 
    while (n != 0) { 
        int leading = n / divisor;  
        int trailing = n % 10; 
        if (leading != trailing)   
            return 0; 
        n = (n % divisor) / 10; 
        divisor = divisor / 100; 
    } 
    return 1; 
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t, a, b;
    cin >>t;
    while(t--){
        cin >>a >>b;
        int ans = 0;
        for(int i=a; i<=b; i++)
            ans += checkPrime(i);
        cout <<ans <<"\n";
    }
    return 0;
}