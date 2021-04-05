#include<bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    long long n;
    while(cin >>n){
        long long c = 0;
        while(n){
            n = n&(n-1);
            c++;
        }
        cout <<c <<"\n";
    }
    return 0;
}