#include<bits/stdc++.h>
using namespace std;

int arr[40] = {0};

long func(long n){
    if(n <= 2)
        return arr[n] = n;
    if(n == 3)
        return arr[n] = 4;
    if(arr[n])
        return arr[n];
    return arr[n] = func(n-1) + func(n-2) + func(n-3);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    long n;
    cin >>n;
    cout <<func(n);
    return 0;
}