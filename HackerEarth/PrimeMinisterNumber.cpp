#include<bits/stdc++.h>
using namespace std;

bool isPrime(long n){
    if (n == 1){
        return false;
    }
    long i = 2;
    while (i*i <= n){
        if (n % i == 0){
            return false;
        }
        i += 1;
    }
    return true;
}

long digitSum(long no){
    return no == 0 ? 0 : no%10 + digitSum(no/10); 
}

bool check(long n){
    return (isPrime(n) && isPrime(digitSum(n)));
}

int main(){
    long a, b;
    cin >>a >>b;
    for(long i=a; i<=b; i++){
        if(check(i)){
            cout <<i <<" ";
        }
    }
    return 0;
}