#include<bits/stdc++.h>
using namespace std;

int main(){
    long long n;
    cin >>n;
    long long x = sqrt(n);
    while(n%x != 0)
        x--;
    long long y = n/x;
    cout <<x+y <<"\n";
    return 0;
}